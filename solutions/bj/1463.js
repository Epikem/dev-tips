
function solve() {
    let n = parseInt(readInts()[0]);
    it(n);
  
    let arr = {1:-1};
    let nextArr = {1:0};
    let t = 1;
    while (JSON.stringify(arr) != JSON.stringify(nextArr)) {
      step('step');
      arr = nextArr;
      for (let i = 2; i < 1000002; i++) {
        if (i % 3 == 0) {
          // it('3');
          nextArr[i] = Math.min(nextArr[i / 3] + 1, nextArr[i - 1] + 1);
        } else if (i % 2 == 0) {
          // it('2');
          nextArr[i] = Math.min(nextArr[i / 2] + 1, nextArr[i - 1] + 1);
        } else {
          // it('1');
          nextArr[i] = nextArr[i - 1] + 1;
        }
      }
      // arr = 1;
    }
    it(arr);
    print(arr[n]);
  
  }