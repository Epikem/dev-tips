# switch-with-enum-or-iterable-type

언어별 스위치 문 사용 방법

2018-09-16

--------------------------


- [cpp](#cpp)
- [ref](#ref)
- [tags](#tags)

## cpp
cpp에서는 enum으로 할 경우 입력이 다른 입력일 때 형변환이 필요한데, `unordered_map`을 쓰면 된다.
아래 코드 예제에서는 `std::string`을 `commands` enum 타입으로 매핑해서 쓴다.
`m.find()`는 찾은 결과를 반환하며, `first`는 `std::string`입력, `second`는 찾으려는 `commands`가 된다.

```cpp
enum commands {
  push = 1,
  pop = 2,
  size = 3,
  empty = 4,
  top = 5,
};

const std::unordered_map<std::string, commands> m{
  {"push", commands::push},
  {"pop", commands::pop},
  {"size", commands::size},
  {"empty", commands::empty},
  {"top", commands::top},
};

commands cmd = m.find(inputs[0]) -> second;
switch (cmd)
{
case push:
  cin >> inputs[1];
  arr.push_back(inputs[1]);
  break;
case pop:
  if (arr.empty()) {
    cout << -1 << endl;
  }
  else {
    cout << arr.back() << endl;
    arr.pop_back();
  }
  break;
case size:
  cout << arr.size() << endl;
  break;
case empty:
  cout << ((arr.size() == 0) ? 1 : 0) << endl;
  break;
case top:
  if (arr.empty()) {
    cout << -1 << endl;
  }
  else {
    cout << arr.back() << endl;
  }
  break;
default:
  break;
}

```


## ref

## tags
  #algorithm, #polyglot



--------------------------


 