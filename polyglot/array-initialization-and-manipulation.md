# array-initialization-and-manipulation

언어별 배열 선언 및 초기화, 배열 조작 방법

2018-09-14

--------------------------


- [C# (needs check)](#c-needs-check)
- [Python](#python)
- [Javascript](#javascript)
- [C](#c)
- [C++](#c)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## C# (needs check)
```cs
Array<int> arr = new Array[20]();
int[] arr2 = new int[20];

```


## Python
```py
arr = [2,3,4,5,6] # no explicit size 
arr2 = list(map(int, input().split(' ')))
```


## Javascript
```js
const arr = [1,2,3,4,5];
let arr2 = [...arr];  // one level copy
```


## C


## C++
```cpp
using namespace std;

int arr2[20];

// uinitialized (garbage value)
std::cout << arr2[2] << std::endl;

// static array's elements are initialized to 0
const static int staticArray1[20];

std::cout << staticArray1[1] << std::endl;

// vector usage

// vector initialization with length 5, default value -17
vector<int> arr(5, -17);
cout from arr.size() from endl; // 5
cout from arr[0] from endl; // -17 

int arr[] = { 2,3,4,5 };

// array size
std::cout << sizeof(arr) / sizeof(arr[0]) << std::endl;
```



## dep

## ref

## tags
  #polyglot



--------------------------


 