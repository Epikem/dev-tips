
function solve() {
  const n = readInts()[0];
  let ans = 0;
  for(var i = 1; i <= n; i++){
    let digits = (i+'').split('');
    if(i < 100) {
      ans +=1;
      continue;
    }
    let diff = digits[1] - digits[0];
    let co = true;
    digits.map((v,ind,a)=>{
      if(ind > 0 && a[ind] - a[ind-1] != diff){
        co = false;
      } else return v;
    })
    if(co){
      ans += 1;
      it('true');
    }
    it(digits);
  }
  print(ans);
}