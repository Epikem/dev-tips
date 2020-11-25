
function solve() {
  var N = readInts()[0];
  var scores = readInts();
  var max = Math.max.apply(Math, _toConsumableArray(scores));
  print(scores.map(function (score) {
    return score / max * 100;
  }).reduce(function (a, b) {
    return a + b;
  }) / N);
}