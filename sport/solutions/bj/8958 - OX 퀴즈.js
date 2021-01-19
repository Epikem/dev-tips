
function solve() {
  const n = readInts()[0];
  for(var tc = 0; tc < n; tc++){
    const line = readline();
    let sum = 0;
    let s = 0;
    it(line);
    for(var c = 0; c < line.length; c++){
      if(line[c] == 'O'){
        s += 1;
        sum += s;
      } else {
        s = 0;
      }
      it(line[c]);
    }
    print(sum);
    it('emd');
  }

}