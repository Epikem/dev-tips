
function solve() {
  let line = readline()
  it(line);
  while(line != '0 0'){
    print(line.split(' ').reduce((a,b)=>(+a + +b)));
    line = readline();
    it(line);
  }
}