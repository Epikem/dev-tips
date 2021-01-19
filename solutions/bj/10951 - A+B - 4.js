
function solve() {
  let line = readline()
  it(line);
  while(line != null){
    print(line.split(' ').reduce((a,b)=>(+a + +b)));
    line = readline();
    it(line);
  }
}
