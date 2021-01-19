// NYAN NYAN
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
// ░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
// ░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
// ░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
// ░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
// ░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
// ░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
// ░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
// ░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
// ░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
// ░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
// ░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

// 백준의 노드 버전이 너무 낮아 babel 사용. 
// 풀이는 solve() 함수에 있음.

const CODEFORCES_NODE = "cf";
const CODEFORCES_V8 = "cf-v8";
const BEAKJOON = "bj";
const TEST = "test";
// var SITE = BEAKJOON;
var SITE = CODEFORCES_NODE;
var DEBUG = false; 

if(SITE == BEAKJOON){
  if (!String.prototype.startsWith) {
    String.prototype.startsWith = function(search, pos) {
      return this.substr(!pos || pos < 0 ? 0 : +pos, search.length) === search;
    };
  }
  if (!String.prototype.endsWith) {
    String.prototype.endsWith = function(search, this_len) {
      if (this_len === undefined || this_len > this.length) {
        this_len = this.length;
      }
      return this.substring(this_len - search.length, this_len) === search;
    };
  }
  if (!String.prototype.repeat) {
    String.prototype.repeat = function(count) {
      'use strict';
      if (this == null) {
        throw new TypeError('can\'t convert ' + this + ' to object');
      }
      var str = '' + this;
      count = +count;
      if (count != count) {
        count = 0;
      }
      if (count < 0) {
        throw new RangeError('repeat count must be non-negative');
      }
      if (count == Infinity) {
        throw new RangeError('repeat count must be less than infinity');
      }
      count = Math.floor(count);
      if (str.length == 0 || count == 0) {
        return '';
      }
      // Ensuring count is a 31-bit integer allows us to heavily optimize the
      // main part. But anyway, most current (August 2014) browsers can't handle
      // strings 1 << 28 chars or longer, so:
      if (str.length * count >= 1 << 28) {
        throw new RangeError('repeat count must not overflow maximum string size');
      }
      var maxCount = str.length * count;
      count = Math.floor(Math.log(count) / Math.log(2));
      while (count) {
         str += str;
         count--;
      }
      str += str.substring(0, maxCount - str.length);
      return str;
    }
  }
}

String.prototype.replaceAt=function(index, replacement) {
  return this.substr(0, index) + replacement+ this.substr(index + replacement.length);
}

Function.prototype.repeat = function(times){
  for(let i = 0; i < times; i++){
    this();
  }
}

Array.prototype.getMaxConsecutiveSum = function(defaultValue = -Infinity){
  const N = this.length;
  let maxsum = defaultValue;
  let cursum = defaultValue;
  let cur;
  for(var ii = 0; ii < N; ii++){
    cur = this[ii];
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
  this.maxConsecutiveSum = maxsum;
  return maxsum;
}

try {
  require('manakin').global;
  // require ("babel-polyfill");
} catch (error) {

}
try {
  process.argv.forEach(function (val, index, array) {
    if (val.startsWith("site")) {
      switch (val.split("=")[1]) {
        case "test":
          // console.log('change site to test')
          SITE = TEST;
          break;
        case "cf-node":
          // console.log('change site to cf')
          SITE = CODEFORCES_NODE;
          break;
        case "cf":
          // console.log('change site to cf')
          SITE = CODEFORCES_NODE;
          break;
        case "cf-v8":
          // console.log('change site to cf')
          SITE = CODEFORCES_V8;
          break;
        case "bj":
          // console.log('change site to bj')
          SITE = BEAKJOON;
          break;
      }
    }
    if (val.startsWith("debug")) {
      switch (val.split("=")[1]) {
        case "true":
          DEBUG = true;
          break;
        case "false":
          DEBUG = false;
          break;
      }
    }
  });
} catch (error) {
}

let inputFilePath = '';
switch(SITE){
  case TEST:
    const config = require('config');
    var fs = require("fs");
    var path = require('path');
    inputFilePath = config.get('INPUTFILEPATH') || path.resolve(__dirname, "input.txt");
    break;
  default:
    inputFilePath = './input.txt';
    break;
}
const INPUTFILEPATH = inputFilePath;

// if (!String.prototype.endsWith) {
// 	String.prototype.endsWith = function(search, this_len) {
// 		if (this_len === undefined || this_len > this.length) {
// 			this_len = this.length;
// 		}
// 		return this.substring(this_len - search.length, this_len) === search;
// 	};
// }
// if (!Array.prototype.includes) {
//   Array.prototype.includes = function (target) {
//     return this.indexOf(target) !== -1
//   }
// }

const newLine = '\n';
var ans;
var inputText = "";
var lineCount = 0;
var lines;
var input;
var readline;
var getlines;
var lineOpen = false;
var readingLine = '';

var clockStart;
var clock;

var print;
print = console.log;
var it;
var step;
function EnableLogging(){
  it = console.info;
  step = console.success;
}
function DisableLogging(){
  it = function it(params) {
    return 0;
  }
  step = it;
}
if (DEBUG) {
  EnableLogging();
  clock = function(start) {
    if ( !start ) return process.hrtime();
    var end = process.hrtime(start);
    return Math.round((end[0]*1000) + (end[1]/1000000));
  }
} else {
  DisableLogging();
}

// prepares test data. to replace line input, assign arrays to lines variable.
function prepareTestData() {
  // it(lines);

  // lines = ['custom line 1', 'custom line 2'];
}

// executes exactly once for both test and run. execution time will be included to elapsed time. 
const prepareSolve = () => {
  
}

function power(x, y) {    //분할 정복을 이용하여 x^y 구하기
  let ret = 1;
  while (y > 0) {
    if (y % 2) {
        ret *= x;
        ret %= P;
    }
    x *= x;
    x %= P;
    y /= 2;
  }
  return ret;
}

function createArray(lengths) {
  var arr = new Array(lengths || 0),
    i = lengths;
  if (arguments.length > 1) {
    var args = Array.prototype.slice.call(arguments, 1);
    while (i--) arr[lengths - 1 - i] = createArray.apply(this, args);
  }
  return arr;
}

function numericSortList(list){
  list.sort((a,b)=>a-b);
}

// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ MAIN SOLVE FUNCTION ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

function getIntersection(r1, r2)
{
    if(r1.x > r2.x+r2.w) return null;
    if(r1.x+r1.w < r2.x) return null;
    if(r1.y > r2.y+r2.h) return null;
    if(r1.y+r1.h < r2.y) return null;

    var rect = {};
    rect.x = Math.max(r1.x, r2.x);
    rect.y = Math.max(r1.y, r2.y);
    rect.w = Math.min(r1.x+r1.w, r2.x+r2.w)-rect.x;
    rect.h = Math.min(r1.y+r1.h, r2.y+r2.h)-rect.y;

    return rect;
}

// 출처: https://tibyte.kr/228 [티바이트]

//[-1,1,-2,2,-3,3,...]

function getAffectedArea(r, color){
  // w, h가 모두 홀일 때, 시작점이 반대색(채울 색)이면 Math.floor(w*h/2)+1개 먹고, 아니면 Math.floor(w*h/2)개 먹는다.
  // 7 5
  // 4 8
  it(r, color);
  // it(r.x, r.y, r.w);
  if(r == null) return 0;
  if((r.x + r.y) % 2 == 0){ //white 위치
    if(color == 'b' && r.w % 2 == 1 && r.h % 2 == 1){
      return Math.floor(r.w / 2.0 * r.h) + 1;
    }else {
      return Math.floor(r.w / 2.0 * r.h);
    }
  }
  if((r.x + r.y )% 2 == 1){
    if(color == 'w' && r.w % 2 == 1 && r.h % 2 == 1){
      return Math.floor(r.w / 2.0 * r.h) + 1;
    }else {
      return Math.floor(r.w / 2.0 * r.h);
    }
  }
}
function getRandomNumber(to, from){
  if(from == undefined){
    return Math.floor(Math.random()*to + 1);
  }
  return Math.floor(Math.random()*(to - from) + from);
}
function solve(){

  var found = false;
  var i = 1;
  while(!found){
    i*=2;
    if(i == i - 1){
      found= true;
    }
    // if(Math.floor(i / 2.0 * i) + 1 == Math.floor(i / 2.0 * i)){
    //   found = true;
    // }
  }
  print(i, Math.floor(i / 2.0 * i));
  return;
  const [T] = readInts();
  var [n,m,x1,x2,y1,y2,x3,x4,y3,y4] = [0];
  let interSectionArea = 0;

  for(var t = 0 ; t<T;t++){
    var mapp = createArray(500,500);
    // [n,m] = readInts();
    // [x1,y1,x2,y2] =readInts();
    // [x3,y3,x4,y4] =readInts();

    [n,m] = [getRandomNumber(200), getRandomNumber(200)];
    [x1,y1,x2,y2] =[getRandomNumber(m), getRandomNumber(n), getRandomNumber(m), getRandomNumber(n)];
    [x3,y3,x4,y4] =[getRandomNumber(m), getRandomNumber(n), getRandomNumber(m), getRandomNumber(n)];
    if(x1 > x2) [x1,x2] = [x2,x1];
    if(x3 > x4) [x3,x4] = [x4,x3];
    if(y1 > y2) [y1,y2] = [y2,y1];
    if(y3 > y4) [y3,y4] = [y4,y3];
    it(n,m,x1,x2,y1,y2,x3,x4,y3,y4)
    var anss = 0;
    for(var i = 1; i <= m; i++){
      for(var j = 1; j <= n; j++){
        if((i+j)%2 == 1){
          mapp[i][j] = 1;
        } else mapp[i][j] = 0;
        if(x1 <= i && i <= x2 && y1 <= j && j <= y2){
          mapp[i][j] = 0;
        }
        if(x3 <= i && i <= x4 && y3 <= j && j <= y4){
          mapp[i][j] = 1;
        }
        if(mapp[i][j] == 1){
          anss++;
        }
      }
    }
    // for(var i = 1; i <= m; i++){
    //   it(mapp[i]);
    // }

    var wboard = {
      x:0,y:0,w:m,h:n
    }
    var r1 = {
      x: x1-1,y:y1-1,w:x2-x1+1,h:y2-y1+1
    }
    var r2 = { x: x3-1, y: y3-1, w:x4-x3+1, h:y4-y3+1};
    it('intersection :')
    it(r1, r2);
    var intersectedArea = getAffectedArea(getIntersection(r1,r2), 'w');
    it(intersectedArea)
    // it(intersectedArea);
    // 어떤 경우에 겹치나? x1~x2범위랑 y1~y2범위가 x3~x4, y3~y4와 걸칠 때.
    it('board :')
    // 안겹치는 경우는? x1 > x4이거나, x2 < x3이거나, y에 대해서 그럴 때,
    let whites = getAffectedArea(wboard, 'b');
    let blacks = getAffectedArea(wboard, 'w');
    // it(getAffectedArea(wboard, 'b'));
    // it(getAffectedArea(wboard, 'w'));
    // it(getAffectedArea(r1, 'w') - intersectedArea - getAffectedArea(r2, 'b'));
    it('calc :')
    whites += +getAffectedArea(r1, 'w') - intersectedArea - getAffectedArea(r2, 'b');
    blacks += -getAffectedArea(r1, 'w') + intersectedArea + getAffectedArea(r2, 'b');

    // print(getAffectedArea(r1, 'w') - intersectedArea + getAffectedArea(r2, 'b'));
    print(whites, blacks);
    it('real ans : ' + anss);
    if(blacks != anss) {
      print('WRONG')
      console.warn('WRONG ' + blacks, anss);
    }
  }
}

// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

function resetRead(){
  lineCount = 0;
}

function checkMemoryUsage() {
  it(process.memoryUsage());
}

function readOne(separator=' ') {
  if(lineOpen && readingLine != null){
  // if(lineOpen){
    // it(readingLine);
    let splitPos = readingLine.search(separator)
    
    let ret = readingLine.slice(0, splitPos);
    if(splitPos == -1){
      // it('close');
      ret = readingLine;
      readingLine = '';
      lineOpen = false;
    }
    readingLine = readingLine.substr(splitPos + 1)
    // it(ret, readingLine, splitPos);
    return ret;
  } else {
    readingLine = readline();
    lineOpen = true;
    if(readingLine == null) return '';
    return readOne(separator);
  }
}

function readInts() {
  try {
    lineOpen = false;
    return readline()
      .split(" ")
      .map(x => parseInt(x));
  } catch (error) {
    console.error(error);
    return null;
  }
}

switch (SITE) {
  case TEST:
    var fs = require("fs");
    var path = require('path');
    // input = fs.createReadStream(path.resolve(__dirname, "input.txt"), {
    //   encoding: "utf8"
    // });
    input = fs.createReadStream(INPUTFILEPATH, {
      encoding: "utf8"
    });

    function inputListener(line) {
      console.log(line);
      if(line.startsWith('end')){
        console.log('end');
        closing();
      }
      if (!line) {
        closing();
      }
      lineCount++;
      inputText += line + "\r\n";
    }


    function readlines() {
      const readline = require("readline");
      const rl = readline.createInterface({
        input,
        output: process.stdout,
        terminal: false
      });
      rl.on("line", inputListener);
      rl.on('close', closing);
    }

    getlines = function* (inputText) {
      var lines = inputText.split(/\r?\n/);
      for (let line of lines) {
        yield line + newLine;
      }
    }

    readline = function () {
      return lines.next().value.trim();
    }

    readlines();

    break;

  case CODEFORCES_NODE:
    input = process.stdin;

    function inputListener(line) {
      if (!line) {
        closing();
      }
      lineCount++;
      inputText += line + "\r\n";
    }

    function readlines() {
      const readline = require("readline");
      const rl = readline.createInterface({
        input,
        output: process.stdout,
        terminal: false
      });
      rl.on("line", inputListener);
      rl.on('close', closing);
    }

    getlines = function* (inputText) {
      var lines = inputText.split(/\r?\n/);
      for (let line of lines) {
        yield line + newLine;
      }
    }

    readline = function () {
      return lines.next().value.trim();
    }

    readlines();

    break;
  case BEAKJOON:
    var fs = require('fs');
    if (DEBUG) {
      // input = fs.readFileSync('./input.txt').toString();
      inputText = fs.readFileSync(INPUTFILEPATH).toString();
      
    } else {
      inputText = fs.readFileSync('/dev/stdin').toString();
    }

    readline = function () {
      lineCount++;
      let line = lines[lineCount - 1];
      if (line)
        return lines[lineCount - 1].trim();
      else return null;
    }

    getlines = function (inputText) {
      lineCount = 0;
      return inputText.split(/\r?\n/);
    }

    // lines = getlines(input);
    closing();
    break;
  default:
    break;
}

function closing() {
  if(DEBUG){
    DisableLogging();
    const prepareClock = clock();
    lines = getlines(inputText);
    prepareSolve();
    const prepareClockElapsedTime = clock(prepareClock);
    EnableLogging();
    prepareTestData();
    solve();
    resetRead();
    console.warn('performance check');
    DisableLogging();
    clockStart = clock();
    // lines = getlines(inputText);
    solve();
    console.warn(`${clock(clockStart) + prepareClockElapsedTime} ms`);
    EnableLogging();
    process.exit();
  } else {
    lines = getlines(inputText);
    prepareSolve();
    solve();
    process.exit();
  }
}