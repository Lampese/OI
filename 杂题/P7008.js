const fs=require('fs')
const data=fs.readFileSync('/dev/stdin')
const result=data.toString('ascii').trim().split('\n');
let T=Number(result.shift());
while(T--){
    let line=result.shift().split(' '),shield=[];
    while(true){
        if(result[0]!="what does the fox say?")shield.push(result.shift().split(' ')[2]);
        else{
            result.shift();
            break;
        }
    }
    line.filter(v=>!shield(includes(v))).forEach(v=>process.stdout.write(v+' '))
    process.stdout.write('\n');
}