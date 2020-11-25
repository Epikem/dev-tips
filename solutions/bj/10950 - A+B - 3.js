
function solve() {
  const T = readInts()[0];
  const getSum = () => {
    const [a,b] = readInts();
    print(a+b);
  }
  getSum.repeat(T);
}