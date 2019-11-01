const fs = require("fs");
const { exec } = require('child_process');
var h = ~~(Math.random()*29+1),
    w = ~~(Math.random()*29+1),
    h2 = w,
    w2 = ~~(Math.random()*29+5);
function generate(n){
  var result = "";
  result+=`${h} ${w}\n`;
  console.log(`${h} ${w}`);
  for(var i=0,str;i<h;i++){
    str = "";
    for(var j=0;j<w;j++){
      str+=(Math.random()>.95?(~~(Math.random()*10)):0)+" ";
    }
    result+=str+"\n";
    console.log(str); 
  }
  console.log(`${h2} ${w2}`);
  result+=`${h2} ${w2}\n`;
  for(var i=0,str;i<h2;i++){
    str = "";
    for(var j=0;j<w2;j++){
      str+=(Math.random()>.95?(~~(Math.random()*10)):0)+" ";
    }
    result+=str+"\n";
    console.log(str); 
  }
  fs.writeFileSync(`${n}.in`, result);
  program(n);
}

for(var i=4;i<=100;i++)
  generate(i);


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
