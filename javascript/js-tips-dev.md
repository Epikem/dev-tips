# js-tips-dev

js 리뷰사항으로 알게 된 것 등.

--------------------------

- [삼항 연산자](#삼항-연산자)
- [lodash](#lodash)
  - [set](#set)
- [angular](#angular)
- [debugging](#debugging)
- [important](#important)
- [tags](#tags)

## 삼항 연산자
- 반드시 조건문에 괄호 사용
```js
var a = (value) ? 1 : 2;
```

## lodash

### set
- 키를 깊은 depth로 설정하는 것이 아니면 `_.set(...)`을 굳이 사용할 필요는 없음
- path key가 비었는지 체크 필요

## angular

- 타이밍 문제로 무조건 바로 초기화하는 값도 다른 곳에서는 초기화되지 않았을 수 있다.

## debugging

- 에러 위치가 vendor인 것으로 어디서 에러가 났을지 유추할 수 있다. (라이브러리를 잘못 사용했거나, 라이브러리가 잘못되었거나)

## important

! HTML id 속성값은 유일해야하며, snake_case를 사용해야 한다.
! 개발 원칙 : 
  1. 프로그램이 오동작할지언정 코드 에러가 발생하면 안됨.
  2. 에러가 나더라도 다른 기능은 정상 동작해야 함.
! IE 관련 주의점: 
- Array `includes`, 
- String `includes`, 
- String `startsWith`
위 세 함수 사용하면 IE 호환성 깨진다.


## tags
- javascript
