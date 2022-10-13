var ws=require('ws');
var cmd=require('node-cmd');
const dgram = require('dgram')
const server = dgram.createSocket('udp4')
const wss=new ws.Server({port:16384});
var sockets=[],dnsyes=true;
wss.on('connection',function(ws){
    sockets.push(ws);
    ws.on('message',function(msg){
        let context=JSON.parse(msg);
        console.log(context);
        if(context.user=="admin"){
            sockets.forEach(v=>{if(v!=ws)v.send(msg);});
        }else if(context.user=="server"){
            if(context.type=="play"){
                cmd.run(`play ./music/${context.music}`);
            }else if(context.type=="dns"){
                if(!context.yes==dnsyes){
		            dnsyes=context.yes;
                    console.log(`change dns status to ${dnsyes}`);
                }
            }
        }
    });
    ws.on('close',function(){
        for(let i=0;i<sockets.length;++i){
            if(sockets[i]==this){
                sockets.splice(i,1)
                break;
            }
        }
    });
});
console.log(`dns server starting with...`)
const domain1=/oj.dyyz.oi/, domain2=/share.dyyz.oi/;
const targetIp = '10.10.231.211'
const fallbackServer = '223.5.5.5'
function copyBuffer(src, offset, dst) {
  for (let i = 0; i < src.length; ++i) {
    dst.writeUInt8(src.readUInt8(i), offset + i)
  }
}
function resolve(msg, rinfo) {
  const queryInfo = msg.slice(12)
  const response = Buffer.alloc(28 + queryInfo.length)
  let offset = 0
  const id = msg.slice(0, 2)
  copyBuffer(id, 0, response) 
  offset += id.length
  response.writeUInt16BE(0x8180, offset)
  offset += 2
  response.writeUInt16BE(1, offset)
  offset += 2
  response.writeUInt16BE(1, offset)
  offset += 2
  response.writeUInt32BE(0, offset)
  offset += 4
  copyBuffer(queryInfo, offset, response)
  offset += queryInfo.length
  response.writeUInt16BE(0xC00C, offset)
  offset += 2
  const typeAndClass = msg.slice(msg.length - 4)
  copyBuffer(typeAndClass, offset, response)
  offset += typeAndClass.length
  response.writeUInt32BE(600, offset)
  offset += 4
  response.writeUInt16BE(4, offset)
  offset += 2
  targetIp.split('.').forEach(value => {
    response.writeUInt8(parseInt(value), offset)
    offset += 1
  })
  server.send(response, rinfo.port, rinfo.address, (err) => {
    if (err) {
      console.log(err)
      server.close()
    }
  })
}

function forward(msg, rinfo) {
  const client = dgram.createSocket('udp4')
  client.on('error', (err) => {
    console.log(`client error:\n${err.stack}`)
    client.close()
  })
  client.on('message', (fbMsg, fbRinfo) => {
    server.send(fbMsg, rinfo.port, rinfo.address, (err) => {
      err && console.log(err)
    })
    client.close()
  })
  client.send(msg, 53, fallbackServer, (err) => {
    if (err) {
      console.log(err)
      client.close()
    }
  })
}

function parseHost(msg) {
  let num = msg.readUInt8(0)
  let offset = 1
  let host = ""
  while (num !== 0) {
    host += msg.slice(offset, offset + num).toString()
    offset += num
    num = msg.readUInt8(offset)
    offset += 1
    if (num !== 0) {
      host += '.'
    }
  }
  return host
}
server.on('message', (msg, rinfo) => {
  console.log(msg);
  console.log(rinfo);
  const host = parseHost(msg.slice(12))
  if(domain1.test(host)||domain2.test(host)){
    resolve(msg, rinfo)
  }else{
    if(dnsyes)forward(msg, rinfo)
  }
})
server.on('error', (err) => {
  console.log(`server error:\n${err.stack}`)
  server.close()
})
server.on('listening', () => {
  const address = server.address()
  console.log(`server listening ${address.address}:${address.port}`)
})
server.bind(53)
