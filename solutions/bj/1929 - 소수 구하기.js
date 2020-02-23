
function solve() {
  const MAX = 1000100;
  let primes = [];
  let vals = {2:1};
  const [m, n] = readInts();
  it(m, n);
  for(let i = 3; i < MAX; i+=2){
    vals[i] = 1;
  }
  for(let p = 2; p < MAX; p++){
    if(vals[p] == 2){
      // it(`skip ${p}`)
      continue;
    }
    primes.push(p);
    for(let tt = p; tt < MAX; tt+=p){
      vals[tt] = 2;
    }
  }
  it(vals);

  primes.filter(e=>{
    return e >= m && e <= n;
  }).forEach(e=>print(e));
}