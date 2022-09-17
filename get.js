;;let request=require("request");
request.get({
    url: `https://www.luogu.com.cn/problem/solution/${process.argv[2]}`,
    headers: {                                                   
        cookie:"UM_distinctid=17f388797e34fb-068ba63d77e128-4a4976-1fa400-17f388797e4995; CNZZDATA5476811=cnzz_eid%3D217366004-1630129704-https%253A%252F%252Fwww.luogu.org%252F%26ntime%3D1652106599; __client_id=39b5a589ada3d9f97774a2b87e1fecc0810c752a; _uid=160363"
    },
},
function (error, response, body) {
    if (!error){
        body=eval(body.match(/JSON.\S*\)\);/)[0]).currentData.solutions.result;
        for(let i in body)
            console.log(body[i].content);
    }
})