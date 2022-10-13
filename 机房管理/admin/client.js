var ws=require("ws");
var socket=new ws("ws://10.10.231.211:16384");
socket.on("open",()=>{
    let opt=process.argv;
    if(opt[2]=="play"){
        socket.send(JSON.stringify({user:"admin",type:"play",music:opt[3]}));
    }else if(opt[2]=="fuck"){
        socket.send(JSON.stringify({user:"admin",type:"fuck"}));
    }else if(opt[2]=="serverplay"){
        socket.send(JSON.stringify({user:"server",type:"play",music:opt[3]}));
    }else if(opt[2]=="dns"){
        socket.send(JSON.stringify({user:"server",type:"dns",yes:(opt[3]=="true")?true:false}));
    }
});
socket.on("close",()=>{});
socket.on("message",(data)=>{});