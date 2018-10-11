# convert-between-string-and-int

언어별 문자열과 숫자 변환 방법

2018-09-16

--------------------------


- [c++](#c)
- [python](#python)
- [javascript](#javascript)
	- [string - int](#string---int)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## c++

```cpp
	// std string - int
	string s1 = "12342";
	int i1;

	i1 = std::stoi(s1);

	string s2;
	int i2 = 324524;

	s2 = std::to_string(i2);
	
	// char array - int (internal std::string use)
	const char* cs1 = "3241";
	int ci1;

	ci1 = std::stoi(cs1);

	const char* cs2;
	int ci2 = 22542356;

	cs2 = std::to_string(ci2).c_str();

	// std string - char array
	string ss1("dsdsdd");
	const char* cc1 = ss1.c_str();

	string ss2;
	const char* cc2 = "dsdsddsdss";
	ss2 = cc2;	// implicit cast operator exists.
```


## python


## javascript

### string - int
```js
// str to int
const str1 = "1352523";
const int1 = parseInt(str);

// int to str
const int2 = 1362453;
const str2 = int2.toString(); 
```


## dep

## ref
  - [stackoverflow](https://stackoverflow.com/questions/)
  - [github](https://github.com/Epikem)

## tags
  #polyglot



--------------------------


 