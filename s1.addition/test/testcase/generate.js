const fs = require("fs");

var add = [];
for(var i=0;i<10000;i++)
  add.push(~~(Math.random()*10)+13);
add.sort(v=>Math.random()>.5);
fs.writeFileSync(process.argv[2], add.join("+"));
fs.writeFileSync(process.argv[3], eval(add.join("+")));