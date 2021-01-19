
function solve() {
  // it(readline());
  const N = readInts()[0];
  it(N);
  let diff = 6;
  let cur = 1;
  let ans = 1;
  while(cur < N){
    cur += diff;
    diff += 6;
    ans += 1;
  }
  print(ans);
}