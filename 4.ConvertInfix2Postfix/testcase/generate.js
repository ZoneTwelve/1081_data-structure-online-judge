const fs = require("fs");
const { exec } = require('child_process');
let symbol = "+-*/";
let num = "abc0123456789xyz";

function generate(n){
  let result = func();
  console.log(n, result);
  fs.writeFileSync(`${n}.in`, result);
  program(n);
}

function func(rec = 1){
  let bracket = Math.random()>0.5;
  if(rec==1){
    return func(rec-0.1)+symbol[~~(Math.random()*symbol).length]+func(rec-0.1);
  }else{
    if(Math.random()<rec){
      if(bracket){
        return "("+func(rec/2)+symbol[~~(Math.random()*symbol).length]+func(rec/2)+")";
      }else{
        return func(rec/3*2)+symbol[~~(Math.random()*symbol).length]+func(rec/3*2);
      }
    }else{
      return num[~~(Math.random()*num.length)];
    }
  }
}
//console.log(func());

function program(i){
  exec(`./program < ${i}.in > ${i}.out`, (error, stdout, stderr) => {
    if (error) {
      //console.error(`exec error: ${error}`);
      return;
    }
    //console.log(`stdout: ${stdout}`);
    //console.log(`stderr: ${stderr}`);
  });
}


for(var i=3;i<=100;i++)
  generate(i);