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
var SITE = BEAKJOON;
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


// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ MAIN SOLVE FUNCTION ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

function getAns(linelen){
  const n = linelen;
  
  var baseShape = ['*'];
  var curShape = baseShape;
  var getNextShape = function getNextShape() {
    var nextShape = [];
    curShape.forEach(function (e) {
      nextShape.push(e + e + e);
    });
    curShape.forEach(function (e) {
      nextShape.push(e + ' '.repeat(e.length) + e);
    });
    curShape.forEach(function (e) {
      nextShape.push(e + e + e);
    });
    curShape = nextShape;
  };
  var ii = 1;
  while (ii < n) {
    getNextShape();
    ii = curShape.length;
  }

  return curShape;
}

let ranges = [];
for (let i = 1; i <= 15; i++) {
  ranges.push(Math.pow(2,i));
}

function getDimension(r,c){


  let k = 2, l = 2;
  for (let i = 0; i < ranges.length; i++) {
    if(k-1 < r) k = ranges[i];
    if(l-1 < c) l = ranges[i];
  }

  const dimension = Math.max(k, l);
  return dimension;
}

function getAns(input){
  let [N, r, c] = input.split(' ');
  it(N, r, c);
  let ans = 0;
  let n = 1;
  while(true){
    let dimension = getDimension(r, c);
    dimension/=2;
    if(r >= dimension && c >= dimension){
      r-=dimension;
      c-=dimension;
      ans+=dimension*dimension*3;
    } else if(r >= dimension && c < dimension){
      r-=dimension;
      ans+=dimension*dimension*2;
    } else if(r < dimension && c >= dimension){
      c-=dimension;
      ans+=dimension*dimension;
    } else{
      it('error');
    }

    if(r == 0 && c == 0){
      break;
    }
  }
  return ans;
}

// test('d0', ()=>{
//   expect(getDimension(0,0)).toBe(2);
// })
// test('d1', ()=>{
//   expect(getDimension(1,1)).toBe(2);
// })
// test('d2', ()=>{
//   expect(getDimension(0,2)).toBe(4);
// })
// test('d3', ()=>{
//   expect(getDimension(2,0)).toBe(4);
// })
// test('d4', ()=>{
//   expect(getDimension(2,2)).toBe(4);
// })
// test('d5', ()=>{
//   expect(getDimension(4,2)).toBe(8);
// })

// test('t1', () => {
//   expect(+getAns('2 3 1')).toBe(11);
// })

// test('t2', () => {
//   expect(+getAns('3 7 7')).toBe(63);
// })

// test('t3', () => {
//   expect(+getAns('2 2 3')).toBe(13);
// })

// test('t4', () => {
//   expect(+getAns('2 1 1')).toBe(3);
// })

function solve() {
  
  const anss = getAns(readline());

  print(anss);
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