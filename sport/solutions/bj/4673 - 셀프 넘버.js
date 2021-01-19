
function solve() {
  const M = 10000;
  let n = 1;
  const maps = {};
  let ans = [];
  const nextNum = () => {
    if(!maps[n]){
      ans.push(n);
    }
    if(n < 10){
      maps[2*n] = 2;
    } else
      maps[n + n.toString().split('').reduce((a,b)=>+a+ +b)] = 2;
    n++;
  }
  nextNum.repeat(M+1);
  it(maps);
  print(ans.join('\n'));
}