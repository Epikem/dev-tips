
function solve() {
  const n = readInts()[0];
  for(var tc = 0; tc < n; tc++){
    const line = readline();
    it(line);
    const arr = [];
    let ans = 'YES';
    for(var c = 0; c < line.length; c++){
      if(line[c] == '('){
        arr.push('(');
      } else {
        if(arr.pop() != '(')
          ans = 'NO';
      }
    }
    if(arr.length>0) ans= 'NO';
    print(ans);
  }

}