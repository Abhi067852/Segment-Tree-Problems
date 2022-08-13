const http=require('http');
const server=http.createServer((req,res)=>
{
    console.log("request as been made");
    console.log(req.method);
    res.setHeader('Content-Type','text/plain');
    res.write("Hello world i am here");
    res.end();
})
server.listen(3000,()=>
{
    console.log("Server is listening");
})
