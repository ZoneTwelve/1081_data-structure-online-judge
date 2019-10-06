const fs = require("fs");

var arr = fs.readFileSync(process.argv[2], "utf8").split(" ").sort((a,b)=>Number(a)>Number(b));
fs.writeFileSync(process.argv[3], arr.join(" "));
