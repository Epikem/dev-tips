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
var SITE = CODEFORCES_NODE;
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
    const n = ri();
    for(var tc=0; tc<n;tc++){
        // ABAZDC BACBAD
        // AGGTAB GXTXAYB
        // aaaa aa
        // 지울수는 있는데 순서는 바꿀 수 없다.
        // 엣지 케이스?
        // abc abc - abc
        // abc cba - a or b or c
        // abc ddd - ""
        // 일단 naive하게 생각한다면, 양쪽 문자열의 모든 지우는 조합을 생각할 수 있다. O(2^a * 2^b). 그러고 나서 서로 같은지 비교. 상상을 초월하는 시간복잡도이다.
        // 한 쪽의 모든 조합을 계산한 다음 그 각각의 조합을 키로 하고, 그 조합의 길이를 값으로 하는 맵을 써서 저장해놓고, 다른 쪽의 조합을 계산할 때 값이 존재한다면 그 키의 값에 따라 최대 길이를 업데이트.
        // O(2^a+2^b)가 된다.
        // 그런데 과연 모든 조합을 계산해야할까? 중요한 특징은, 순서는 유지된다는 것이다. 
        // 트라이 등은 공통된 문자열을 찾을 때 썼는데, 이 경우는 지워가면서 최장 공통을 찾는 것이니. 
        // 수열이라면 O(n)만에도 가능한 것으로 아는데, 문자열이라서 어떻게 할 수 있을지 모르겠다.
        // 그런데 문자열도 현재 보면 그냥 숫자로 바꿔도 되지 않나. 위의 예시를 수로 바꿔보면
        // 010932 102103 -> 0103 이렇게 된다. 어쨌든 최장 문제로 바꿔지지는 않는게 숫자 중복이 있을 수 있다.
        // 재귀 호출과 캐싱을 생각해보자. 함수 f(a,b)는 a배열의 인덱스 a 및 그 이후의 문자열과, b배열의 인덱스 b 및 그 이후의 문자열의 가장 긴 공통된 문자열을 리턴한다고 해보자.
        // f(5,5)=""
        // f(5,4)=""
        // f(4,5)="D"
        // f(4,4)="D"
        // f(3,3)="D"
        // f(2,2)="AD"
        // f(1,1)="BAD"
        // f(0,0)="ABAD"
        // 이 문제에서는 인덱스들이 줄어들면서 답이 점점 길어지는 형태지만, 그렇지 않은 경우도 있을 수 있을까?
        // 그러기 위해서는 f(i,j)까지 구했던 부문자열보다 f(i-1,j-1)에서 구한 부문자열이 다른 같은 길이의 부문자열보다 길어져야 한다. 그런데 인덱스를 하나씩만 움직였으므로 
        // 길이가 2 이상 증가할 리는 없다. 따라서 f(i-1,j-1)에서 다른 부분의 문자열로 답이 바뀐다 하더라도, 길이는 f(i,j)+1일 것이다. 그렇다면 f(k,k)에서 가장 긴 경우만 신경써도 된다는 것일까?
        // 지금 생각하는 방식은 결국 투포인터나 마찬가지인거 같은데, 과연 그것에 반례가 없을까?
        // abcdxyz abxyzcd
        // 자 이경우를 보자. 답은 abcd가 아닌, abxyz이다.
        // f(6,6)=f(5,5)=""
        // f(4,4)="z"
        // f(3,3)="yz"
        // f(2,2)="xyz"
        // f(1,1)="bxyz"
        // 놀랍게도, cd보다 길게 만드는 다른 xyz가 있다면 결국 그게 먼저 읽혀버리므로 그쪽이 답이 된다. 
        // 그러면 이 문제는 f(i+1,j+1)가 구해져 있다면 f(i,j)는 f(i+1,j), f(i,j+1)를 구하고, 각각에 대해 f(i,j)를 구해 긴 것을 사용한다.
        // 그런데 f(i+1,j+1)에 대해 f(i+1,j)나 f(i,j+1)을 어떻게 구하지?
        // 만약 둘 중 하나가 길이가 증가했다면, 그것은 a의 i또는 b의 j 인덱스가 증가한 문자열의 맨 앞에 있다는 것이다.
        // i또는 j인덱스는 이미 아니까 쉽게 가져올 수 있는데, 이것이 증가했는지 확인할 상대편의 이전 맨앞 문자의 인덱스를 알아야 하는게 문제다.
        // 근데 그것은 미리 저장해두고 있었다면 쉽게 해결할 수 있다
        // 따라서 pa,pb를 두고, 현재까지 검색한 a,b문자열의 현재 가장 긴 문자열중 가능한 한 가장 뒤에 있는 문자열을 이루는 문자중의 맨 앞 문자를 가리키는 인덱스 라고 정의하자
        // 그러면 인덱스를 땡길 때 땡긴 문자열의 반대편 문자열에서 그에 해당하는 pa-1또는 pb-1 인덱스부터 검색을 시작하면 될 것이다.
        // 이 정보들을 쓰면 그냥 투포인터 문제이므로 O(a+b)만에 풀 수 있을거같다.
        // 그런데, 이렇게 투포인터가 되는 걸 보면 굳이 이렇게 풀 것 없이 pa,pb인덱스 증가시키면서 업데이트가능한 문자가 나오면 1씩 더하는 식으로 하면 될거 같은데?
        // 다만 위의 예시에서 i,j=2일때 B를 먼저 선택하면 틀려진다. A,B모두 선택한 상태여야 함.

        // 아. 잘못 생각한 거 같다. 인덱스를 하나씩만 움직였어도, 바뀐 문자 때문에 2개이상 늘어나는 경우가 있는듯 한데.
        // AGGTAB GXTXAYB
        //
        //0
        //1G
        //2G
        //3GT
        //4GTA
        //5GTAB
        
        // ABAZDC BACBAD
        //0 
        //1A or B
        //2BA
        //3AB or BA
        // AGGTAB GXTXAYB
        let [s1,s2] = rsa();
        let [pa,pb] = [0,0];
        let [ansa, ansb] = ["",""];
        while(s1.length > s2.length){
            s2 = '7'+s2;
        }
        while(s2.length > s1.length){
            s1 = '7'+s1;
        }
        
        for(let i=0;i<Math.max(s1.length,s2.length);i++){
            // a측 기준 검사. s1[i] 에 대해 s2[pb~i]까지 같은 문자가 있는지 검사. 있으면 ansa 업데이트 후 pb를 그 인덱스로 업데이트.
            let ch = s1[i];
            if(ch == ' '){
                ch = s1[s1.length-1];
            }
            // if(ch == undefined){
            //     ch = s1[Math.min(s1.length, s2.length)-1];
            // }
            // it(ansa, ansb);
            for(let j=pb;j<=i;j++){
                it(`ch ${ch} s2[j] ${s2[j]} pb ${pb}`)
                if(s2[j] == ch){
                    ansa+=ch;
                    pb=j+1;
                    break;
                }
            }

            // b
            ch = s2[i];
            if(ch == ' '){
                ch = s2[s2.length-1];
            }
            // if(ch == undefined){
            //     ch = s1[Math.min(s1.length, s2.length)-1];
            // }
            
            for(let j=pa;j<=i;j++){
                it(`ch ${ch} s1[j] ${s1[j]} pa ${pa}`)
                if(s1[j] == ch){
                    ansb+=ch;
                    pa=j+1;
                    break;
                }
            }

            it(`idx ${i} ansa ${ansa}, ansb ${ansb}`)
            // if(ansa.length > ansb.length){
            //     ansb = ansa;
            // } else ansa = ansb;
        }
        //남은 문자 처리.
        
        it(s1,s2);

        print(ansa, ansb);
    }
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