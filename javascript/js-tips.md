# js-tips

js 모르는 것, 몰랐던 것 정리

--------------------------


- [object 비교 시 주의할 점](#object-비교-시-주의할-점)
  - [동등 비교](#동등-비교)
  - [등가 같음](#등가-같음)
  - [느슨한 같음의 es 명세](#느슨한-같음의-es-명세)
  - [엄격한 같음의 es 명세](#엄격한-같음의-es-명세)
  - [부등 비교](#부등-비교)
- [변수 사용과 범위, 호이스팅](#변수-사용과-범위-호이스팅)
  - [함수의 변수 호이스팅 주의](#함수의-변수-호이스팅-주의)
  - [let과 var의 차이](#let과-var의-차이)
  - [array slice와 aplice의 차이, string slice](#array-slice와-aplice의-차이-string-slice)
  - [for..of와 for..in 사용법 차이](#forof와-forin-사용법-차이)
- [ref](#ref)
- [tags](#tags)

## object 비교 시 주의할 점

### 동등 비교
[JS 비교 표](https://dorey.github.io/JavaScript-Equality-Table/)에 모든 비교가 나와 있다.

```js
var a = [1,3,4]
var b = [1,3,4]
var c = "1,3,4"

a == b // false
a == c // true
b == c // true
```
 - a와 c, b와 c의 비교는 배열이 문자열로 implicit coercion되어 true가 되지만, a와 b의 비교는 object reference를 비교하게 되어 false가 된다. object 로 해도 마찬가지일 것.
 - NaN은 자기 자신을 포함한 어떤 값과도 같지 않다. if(x == !x) 를 true로 만드는 유일한 값.
 - 어떤 타입이 숫자로 형 강제(coercion)되었을때 값을 확인해 보려면 단항 연산자 +를 사용하면 된다:

 ```js
 +"3" === 3
 > true
 ```

 <table class="standard-table">
  <thead>
   <tr>
    <th scope="row">&nbsp;</th>
    <th colspan="7" style="text-align: center;" scope="col">피연산자 B</th>
   </tr>
  </thead>
  <tbody>
   <tr>
    <th scope="row">&nbsp;</th>
    <td>&nbsp;</td>
    <td style="text-align: center;">Undefined</td>
    <td style="text-align: center;">Null</td>
    <td style="text-align: center;">Number</td>
    <td style="text-align: center;">String</td>
    <td style="text-align: center;">Boolean</td>
    <td style="text-align: center;">Object</td>
   </tr>
   <tr>
    <th colspan="1" rowspan="6" scope="row">피연산자 A</th>
    <td>Undefined</td>
    <td style="text-align: center;"><code>true</code></td>
    <td style="text-align: center;"><code>true</code></td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>false</code></td>
   </tr>
   <tr>
    <td>Null</td>
    <td style="text-align: center;"><code>true</code></td>
    <td style="text-align: center;"><code>true</code></td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>false</code></td>
   </tr>
   <tr>
    <td>Number</td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>A === B</code></td>
    <td style="text-align: center;"><code>A === ToNumber(B)</code></td>
    <td style="text-align: center;"><code>A === ToNumber(B)</code></td>
    <td style="text-align: center;"><code>A == ToPrimitive(B)</code></td>
   </tr>
   <tr>
    <td>String</td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>ToNumber(A) === B</code></td>
    <td style="text-align: center;"><code>A === B</code></td>
    <td style="text-align: center;"><code>ToNumber(A) === ToNumber(B)</code></td>
    <td style="text-align: center;"><code>A == ToPrimitive(B)</code></td>
   </tr>
   <tr>
    <td>Boolean</td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>ToNumber(A) === B</code></td>
    <td style="text-align: center;"><code>ToNumber(A) === ToNumber(B)</code></td>
    <td style="text-align: center;"><code>A === B</code></td>
    <td style="text-align: center;"><code>ToNumber(A) == ToPrimitive(B)</code></td>
   </tr>
   <tr>
    <td>Object</td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>false</code></td>
    <td style="text-align: center;"><code>ToPrimitive(A) == B</code></td>
    <td style="text-align: center;"><code>ToPrimitive(A) == B</code></td>
    <td style="text-align: center;"><code>ToPrimitive(A) == ToNumber(B)</code></td>
    <td style="text-align: center;"><code>A === B</code></td>
   </tr>
  </tbody>
 </table>

### 등가 같음
이해 잘 안됨. Object.is로 제공된다는데 ===와는 0,-0비교, NaN비교만이 차이가 난다.
아래는 등가 같음 (Object.is 메소드)의 폴리필 코드
```js
if (!Object.is) {
  Object.is = function(x, y) {
    // SameValue 알고리즘
    if (x === y) { // Steps 1-5, 7-10
      // Steps 6.b-6.e: +0 != -0
      return x !== 0 || 1 / x === 1 / y;
    } else {
      // Step 6.a: NaN == NaN
      return x !== x && y !== y;
    }
  };
}
```
### 느슨한 같음의 es 명세


11.9.3 The Abstract Equality Comparison Algorithm

The comparison x == y, where x and y are values, produces true or false. Such a comparison is performed as follows:
```js
    If Type(x) is the same as Type(y), then
        If Type(x) is Undefined, return true.
        If Type(x) is Null, return true.
        If Type(x) is Number, then
            If x is NaN, return false.
            If y is NaN, return false.
            If x is the same Number value as y, return true.
            If x is +0 and y is −0, return true.
            If x is −0 and y is +0, return true.
            Return false.
        If Type(x) is String, then return true if x and y are exactly the same sequence of characters (same length and same characters in corresponding positions). Otherwise, return false.
        If Type(x) is Boolean, return true if x and y are both true or both false. Otherwise, return false.
        Return true if x and y refer to the same object. Otherwise, return false.
    If x is null and y is undefined, return true.
    If x is undefined and y is null, return true.
    If Type(x) is Number and Type(y) is String,
    return the result of the comparison x == ToNumber(y).
    If Type(x) is String and Type(y) is Number,
    return the result of the comparison ToNumber(x) == y.
    If Type(x) is Boolean, return the result of the comparison ToNumber(x) == y.
    If Type(y) is Boolean, return the result of the comparison x == ToNumber(y).
    If Type(x) is either String or Number and Type(y) is Object,
    return the result of the comparison x == ToPrimitive(y).
    If Type(x) is Object and Type(y) is either String or Number,
    return the result of the comparison ToPrimitive(x) == y.
    Return false.
```
NOTE 1 Given the above definition of equality:

    String comparison can be forced by: "" + a == "" + b.
    Numeric comparison can be forced by: +a == +b.
    Boolean comparison can be forced by: !a == !b.

NOTE 2 The equality operators maintain the following invariants:

    A != B is equivalent to !(A == B).
    A == B is equivalent to B == A, except in the order of evaluation of A and B.

NOTE 3 The equality operator is not always transitive. For example, there might be two distinct String objects, each representing the same String value; each String object would be considered equal to the String value by the == operator, but the two String objects would not be equal to each other. For Example:

    new String("a") == "a" and "a" == new String("a")are both true.
    new String("a") == new String("a") is false.

NOTE 4 Comparison of Strings uses a simple equality test on sequences of code unit values. There is no attempt to use the more complex, semantically oriented definitions of character or string equality and collating order defined in the Unicode specification. Therefore Strings values that are canonically equal according to the Unicode standard could test as unequal. In effect this algorithm assumes that both Strings are already in normalised form.


### 엄격한 같음의 es 명세

11.9.6 The Strict Equality Comparison Algorithm

The comparison x === y, where x and y are values, produces true or false. Such a comparison is performed as follows:
```js
    If Type(x) is different from Type(y), return false.
    If Type(x) is Undefined, return true.
    If Type(x) is Null, return true.
    If Type(x) is Number, then
        If x is NaN, return false.
        If y is NaN, return false.
        If x is the same Number value as y, return true.
        If x is +0 and y is −0, return true.
        If x is −0 and y is +0, return true.
        Return false.
    If Type(x) is String, then return true if x and y are exactly the same sequence of characters (same length and same characters in corresponding positions); otherwise, return false.
    If Type(x) is Boolean, return true if x and y are both true or both false; otherwise, return false.
    Return true if x and y refer to the same object. Otherwise, return false.
```
NOTE This algorithm differs from the SameValue Algorithm (9.12) in its treatment of signed zeroes and NaNs.


이런 식으로 할 게 아니라 elm처럼 특정 연산을 어디에서 불러오는지 명시하면 참 좋을 텐데.
`import Object.is as (===)` 또는
`import Compare.is as (===)` 이런 식으로.


### 부등 비교

```js
var a = 11
var b = "epi"
var c = "14"
undefined

a<b
false

a==b
false

a>b
false

a<c
true

a==c
false

a>c
false

b<c
false

b==c
false

b>c
true
```

## 변수 사용과 범위, 호이스팅

### 함수의 변수 호이스팅 주의
```js
function foo(){
  a = 1
}
> undefined

foo()
> undefined

a
> 1 // 자동으로 global variable 생성. 'strict mode'에서는 에러가 남.
```

### let과 var의 차이
let은 while문 등 마지막 블록 내에 존재하고, var는 함수 전체에 존재?

### array slice와 aplice의 차이, string slice
기본적으로 slice는 모든 iterable에 사용가능하다는 것 같다.
그리고 splice는 원본 배열을 변형시키고, 원본에서 제거된 원소들을 리턴한다.

> StackOverflow 펌
Featured snippet from the web
Splice vs Slice
  The splice() method returns the removed item(s) in an array and slice() method returns the selected element(s) in an array, as a new array object.
  The splice() method changes the original array and slice() method doesn't change the original array.

### for..of와 for..in 사용법 차이
of는 각 iterable을 순회할 때 사용.
in은 object의 key를 순회할 때 사용.

## ref

  [mdn](https://developer.mozilla.org/ko/docs/Web/JavaScript/Equality_comparisons_and_sameness)
  [ydkjs](https://github.com/getify/You-Dont-Know-JS/blob/master/up%20%26%20going/ch2.md)
  [JS 비교 표](https://dorey.github.io/JavaScript-Equality-Table/)
## tags
  #javascript
