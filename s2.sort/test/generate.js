const fs = require("fs");
var arr = [];
for(var i=0;i<9999;i++)
  if(i%4==0&&i%7==0||true)
    arr.push(i);
fs.writeFileSync(process.argv[2], arr.join(" "));
fs.writeFileSync(process.argv[3], arr.sort(v=>Math.random()>.5).join(" "));