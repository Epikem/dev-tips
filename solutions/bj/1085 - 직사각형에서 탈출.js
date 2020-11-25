"use strict";
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
const PROGRAMMERS = "ps";
var SITE = BEAKJOON;
// var SITE = CODEFORCES_NODE;
// var SITE = PROGRAMMERS;
var DEBUG = false;
if (SITE == BEAKJOON) {
    if (!String.prototype.startsWith) {
        String.prototype.startsWith = function (search, pos) {
            return this.substr(!pos || pos < 0 ? 0 : +pos, search.length) === search;
        };
    }
    if (!String.prototype.endsWith) {
        String.prototype.endsWith = function (search, this_len) {
            if (this_len === undefined || this_len > this.length) {
                this_len = this.length;
            }
            return this.substring(this_len - search.length, this_len) === search;
        };
    }
    if (!String.prototype.repeat) {
        String.prototype.repeat = function (count) {
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
        };
    }
}
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ HELPER ALGORITHMS/POLYFILLS ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
function getCombinations2(n) {
    let ret = [];
    for (let start = 0; start < n; start++) {
        for (let k = start + 1; k < n; k++) {
            let s = new Set();
            s.add(start);
            s.add(k);
            ret.push(s);
        }
    }
    return ret;
}

function getSubbits(n) {
    let ret = [];
    for (var subset = n; subset; subset = (subset - 1) & n) {
        ret.push(subset);
    }
    return ret;
}
String.prototype.replaceAt = function (index, replacement) {
    return this.substr(0, index) + replacement + this.substr(index + replacement.length);
};
Function.prototype.repeat = function (times, callback = undefined) {
    for (let i = 0; i < times; i++) {
        this();
    }
    return callback ? callback() : null;
};
Array.prototype.getMaxConsecutiveSum = function (defaultValue = -Infinity) {
    const N = this.length;
    let maxsum = defaultValue;
    let cursum = defaultValue;
    let cur;
    for (var ii = 0; ii < N; ii++) {
        cur = this[ii];
        if (cursum + cur > 0) {
            if (cur > cursum + cur) {
                cursum = cur;
            } else
                cursum += cur;
        } else {
            cursum = cur;
            if (maxsum < cursum) {
                maxsum = cursum;
            }
        }
        if (maxsum < cursum) {
            maxsum = cursum;
        }
    }
    this.maxConsecutiveSum = maxsum;
    return maxsum;
};
try {
    require('manakin').global;
    // require ("babel-polyfill");
} catch (error) {}
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
} catch (error) {}
let inputFilePath = '';
switch (SITE) {
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
if (!Array.prototype.sortNumber) {
    /**
     * @memberof Array
     * @summary sorts array by number
     */
    Array.prototype.sortNumber = function (order = 'asc') {
        return this.sort((a, b) => ((order == 'asc') ? 1 : -1) * (+a - +b));
    };
}
const newLine = '\n';
var ans;
var inputText = "";
var lineCount = 0;
var lines;
var input;
/**
 * @type {(trim?=true)=>string}
 */
var readline;
var getlines;
var lineOpen = false;
var readingLine = '';
var clockStart;
var clock;
/**
 * @type {typeof import('glob')}
 */
var glob;
var customFilesPattern = 'inputs/**/*.in';
var customFiles = [];
var print;
print = console.log;
var it;
var step;

function EnableLogging() {
    it = console.info;
    step = console.success;
}

function DisableLogging() {
    it = function it(params) {
        return 0;
    };
    step = it;
}

function RunCustomTests() {
    // glob = require('glob');
    // it(process.cwd());
    // it(process.cwd() + customFilesPattern);
    // glob(customFilesPattern, (er,files)=>{
    //   console.log('files count: ' + files.length);
    //   files.forEach(file=>{
    //     console.log(`custom test case files : ${file}`);
    //     customFiles.push(file);
    //   })
    // });
    // var path2 = process.cwd().replace(/\\/g, "/");
    // path = require('path');
    // glob("*.js", (er,files)=>{
    //   console.log('files count: ' + files.length);
    //   files.forEach(file=>{
    //     console.log(`custom test case files : ${file}`);
    //   })
    // });
    // customFiles.forEach(file=>{
    //   const filePath = process.cwd() + file;
    //   console.info(filePath);
    // })
}
if (DEBUG) {
    EnableLogging();
    clock = function (start) {
        if (!start)
            return process.hrtime();
        var end = process.hrtime(start);
        return Math.round((end[0] * 1000) + (end[1] / 1000000));
    };
} else {
    DisableLogging();
}
// prepares test data. to replace line input, assign arrays to lines variable.
function prepareTestData() {
    // it(lines);
    // lines = ['custom line 1', 'custom line 2'];
}
// executes exactly once for both test and run. execution time will be included to elapsed time. 
const prepareSolve = () => {};

function power(x, y) {
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
        while (i--)
            arr[lengths - 1 - i] = createArray.apply(this, args);
    }
    return arr;
}

function numericSortList(list) {
    list.sort((a, b) => a - b);
}

function getRectangleIntersection(r1, r2) {
    if (r1.x > r2.x + r2.w)
        return null;
    if (r1.x + r1.w < r2.x)
        return null;
    if (r1.y > r2.y + r2.h)
        return null;
    if (r1.y + r1.h < r2.y)
        return null;
    var rect = {};
    rect.x = Math.max(r1.x, r2.x);
    rect.y = Math.max(r1.y, r2.y);
    rect.w = Math.min(r1.x + r1.w, r2.x + r2.w) - rect.x;
    rect.h = Math.min(r1.y + r1.h, r2.y + r2.h) - rect.y;
    return rect;
}

function getRandomNumber(to, from) {
    if (from == undefined) {
        return Math.floor(Math.random() * to + 1);
    }
    return Math.floor(Math.random() * (to - from) + from);
}
/**
 * a queue that will be stop working someday.
 */
class TerminallyIllQueue {
    constructor() {
        this.data = {};
        this.head = 0;
        this.tail = 1;
    }
    length() {
        return this.tail - this.head - 1;
    }
    enqueue(v) {
        this.data[this.tail - 1] = v;
        this.tail++;
    }
    dequeue() {
        const v = this.data[this.head];
        this.head++;
        return v;
    }
}
/**
 * @template T
 * @type {TwoDimensionalMap<T>}
 */
class TwoDimensionalMap {
    constructor() {
        this.data = {};
    }
    /**
     * @memberof TwoDimensionalMap<T>
     * @public
     * @param {number} x
     * @param {number} y
     * @returns {T}
     */
    getPosition(x, y) {
        return this.data[`${x}.${y}`];
    }
    /**
     * @memberof TwoDimensionalMap<T>
     * @public
     * @param {number} x
     * @param {number} y
     * @param {T} value
     */
    setPosition(x, y, value) {
        this.data[`${x}.${y}`] = value;
    }
}
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ MAIN SOLVE FUNCTION ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
function solve() {
    const [x, y, w, h] = ria();

    const xd = Math.min(Math.abs(x-w),x);
    const yd=Math.min(Math.abs(y-h),y);
    print(Math.min(xd,yd));
}
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
function resetRead() {
    lineCount = 0;
}

function checkMemoryUsage() {
    it(process.memoryUsage());
}

function readOne(separator = ' ') {
    if (lineOpen && readingLine != null) {
        // if(lineOpen){
        // it(readingLine);
        let splitPos = readingLine.search(separator);
        let ret = readingLine.slice(0, splitPos);
        if (splitPos == -1) {
            // it('close');
            ret = readingLine;
            readingLine = '';
            lineOpen = false;
        }
        readingLine = readingLine.substr(splitPos + 1);
        // it(ret, readingLine, splitPos);
        if (ret == '' || ret == separator) {
            return readOne(separator);
        } else {
            return ret;
        }
    } else {
        readingLine = readline();
        lineOpen = true;
        if (readingLine == null)
            return '';
        return readOne(separator);
    }
}

function ri() {
    return +readOne();
}

function ria() {
    return readInts();
}
/**
 * @return {string}
 */
function rs() {
    return readOne();
}
/**
 * @return {string[]}
 */
function rsa() {
    return readline().split(' ');
}
/**
 * @returns {number[]}
 */
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
let inputListener;
let readlines;
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
        inputListener = (line) => {
            console.log(line);
            if (line.startsWith('end')) {
                console.log('end');
                closing();
            }
            if (!line) {
                closing();
            }
            lineCount++;
            inputText += line + "\r\n";
        };
        readlines = () => {
            const readline = require("readline");
            const rl = readline.createInterface({
                input,
                output: process.stdout,
                terminal: false
            });
            rl.on("line", inputListener);
            rl.on('close', closing);
        };
        getlines = function* (inputText) {
            var lines = inputText.split(/\r?\n/);
            for (let line of lines) {
                yield line + newLine;
            }
        };
        readline = function (trim = true) {
            const lineval = lines.next().value;
            return trim ? lineval.trim() : lineval;
        };
        readlines();
        break;
    case CODEFORCES_NODE:
        input = process.stdin;
        inputListener = (line) => {
            if (!line) {
                closing();
            }
            lineCount++;
            inputText += line + "\r\n";
        };
        readlines = () => {
            const readline = require("readline");
            const rl = readline.createInterface({
                input,
                output: process.stdout,
                terminal: false
            });
            rl.on("line", inputListener);
            rl.on('close', closing);
        };
        getlines = function* (inputText) {
            var lines = inputText.split(/\r?\n/);
            for (let line of lines) {
                yield line + newLine;
            }
        };
        readline = function (trim = true) {
            const lineval = lines.next().value;
            return trim ? lineval.trim() : lineval;
        };
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
        readline = function (trim = true) {
            lineCount++;
            let line = lines[lineCount - 1];
            if (line)
                return trim ? lines[lineCount - 1].trim() : lines[lineCount - 1];
            else
                return null;
        };
        getlines = function (inputText) {
            lineCount = 0;
            return inputText.split(/\r?\n/);
        };
        // lines = getlines(input);
        closing();
        break;
    case PROGRAMMERS:
        //자체 함수를 실행할 것이므로 아무것도 하지 않는다.
    default:
        break;
}

function closing() {
    if (DEBUG) {
        DisableLogging();
        const prepareClock = clock();
        lines = getlines(inputText);
        prepareSolve();
        const prepareClockElapsedTime = clock(prepareClock);
        EnableLogging();
        prepareTestData();
        solve();
        console.warn('done. running custom tests');
        RunCustomTests();
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