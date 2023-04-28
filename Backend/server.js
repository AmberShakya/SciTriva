const express = require("express");
const cors = require("cors");
const app = express();
const bodyParser = require("body-parser");
const cpp = require('compile-run');
const { runCppFile, runCppFileAndReturnPromise } = require("compile-run/dist/lib/cpp/run-file");

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended:true}))
app.use(cors())

app.get("/login",function(req,res){
    var pass = req.query.password;
    var email = req.query.email;
    var s = email+"\n"+pass;
    let resultPromise = runCppFileAndReturnPromise('./login.cpp', { stdin:s});
resultPromise
    .then(result => {
        let status = result.stdout;
        var message;
        if(status == 200){
            message = "Successfully logged in!!";
        }
        else if(status == 300){
            message = "Incorrect password";
        }
        else if(status == 500){
            message = "User has to sign up";
        }
        else if(status == 404){
            message = "Server error";
        }
        res.json({result:message});
    })
    .catch(err => {
        console.log(err);
        res.json({error:err});
    });
})

app.post("/signup",(req,res)=>{
    var pass = req.headers["password"];
    var email = req.body.email;
    var username = req.body.username;
    var s = username+"\n"+email+"\n"+pass;
    let resultPromise = runCppFileAndReturnPromise('./signup.cpp', { stdin:s});
resultPromise
    .then(result => {
        var status = result.stdout;
        var message;
        if(status == "200"){
            message = "User added successfully!!";
        }
        else if(status == "500"){
            message = "User already exists";
        }
        else if(status == "404"){
            message = "Server error";
        }
        res.json({result:message});
    })
    .catch(err => {
        console.log(err);
        res.json({error:err});
    });


})

app.get("/leaderboard",(req,res)=>{
    let resultPromise = runCppFileAndReturnPromise('./leaderboardget.cpp', {});
resultPromise
    .then(result => {
        var status = result.stdout;
        var message;
        if(status == "404"){
            message = "Server error";
            res.json({result:message})
        }
        else{
            var s = status;
            var a = status.split("&&&");
            var arr = [];
            var k;
            for(let i = 0; i<a.length; i++){
                if(a[i].length>1){
                    k = a[i].split("***");
                    arr.push(k);
                }
            }
            res.json({result:arr});
        }
        
    })
    .catch(err => {
        console.log(err);
        res.json({error:err});
    });
})

app.post("/leaderboard",(req,res)=>{
    var score = req.body.score;
    var email = req.body.email;
    var inp = score+"\n"+email;
    let resultPromise = runCppFileAndReturnPromise('./leaderboardpost.cpp', {stdin:inp});
resultPromise
    .then(result => {
        var status = result.stdout;
        res.json({result:status});
    })
    .catch(err => {
        console.log(err);
        res.json({error:err});
    })
})

app.listen(3000,function(err){
    console.log("server running at 3000");
})