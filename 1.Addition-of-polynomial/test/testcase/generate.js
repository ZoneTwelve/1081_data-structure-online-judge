const fs = require("fs");
const { exec } = require('child_process');

function program(i){
  exec(`./program.out < ${i}.in > ${i}.out`, (error, stdout, stderr) => {
    if (error) {
      //console.error(`exec error: ${error}`);
      return;
    }
    //console.log(`stdout: ${stdout}`);
    //console.log(`stderr: ${stderr}`);
  });
}

function generate(){
  var max = ~~(Math.random()*1000)+24;
  var k = ~~(Math.random()*2048)-1024;
  if(k==0)k = 2;
  var arr = [`${Math.abs(k)==1?"":k}x^${max}`];
  for(max-=~~(Math.random()*10+10);max>=0;max-=(~~(Math.random()*10)+1)){
    var c = ~~(Math.random()*2048)-1024, e = max;
    if(c==0)c = 3;
    arr.push(`${c>0?"+":""}${c}${max==0?"":"x^"}${max!=0?max:""}`);
  }
  return arr.join("");
}
//return console.log(generate().join("\n"));
for(var i=0;i<18;i++){
  var testcase = `${generate()}
${generate()}`;
  console.log(i, testcase);
  fs.writeFileSync(`${i+1}.in`, testcase);
  program(i+1);
}
//console.log(generate());