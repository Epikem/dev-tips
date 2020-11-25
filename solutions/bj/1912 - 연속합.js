
function solve() {
  const N = readInts()[0];
  let maxsum = -1001;
  let cursum = -1001;
  let cur;
  for(var ii = 0; ii < N; ii++){
    it(cursum)
    cur = +readOne(' ');
    if(cursum + cur > 0){
      if(cur > cursum + cur){
        cursum = cur;
      } else cursum += cur;
    } else {
      cursum = cur;
      if(maxsum < cursum){
        maxsum = cursum;
      }
    }
    if(maxsum < cursum){
      maxsum = cursum;
    }
  }
  print(maxsum);
}