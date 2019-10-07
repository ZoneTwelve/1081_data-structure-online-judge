const fs = require("fs");
const { exec } = require('child_process');

function program(i){
  exec(`./a.out < ${i}.in > ${i}>.out`, (error, stdout, stderr) => {
    if (error) {
      console.error(`exec error: ${error}`);
      return;
    }
    console.log(`stdout: ${stdout}`);
    console.log(`stderr: ${stderr}`);
  });
}

function generate(){
  
}
var str;
for(var n=0;n<100;n++){
  var len = ~~(Math.random()*-20)+~~(Math.random()*30);
  str = [`${~~(Math.random()*10)}x^${~~(Math.random()*10)+50}`];
  console.log(len);
  for(var i=~~(Math.random()*30)+10;i>len;i--){
    var k = ~~(Math.random()*6000-1200)+(Math.random()>.5?(~~(Math.random()*500))/1000:0);
    var p = ~~(Math.random()*(n-i));
    k = k>0?`+${k}`:k;
    
    str.push(`${k}${p==0?"":"x^"+p}`);
  }
  console.log(str.join(""));
  
}