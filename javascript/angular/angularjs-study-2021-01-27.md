# angularjs-study-2021-01-27

# angular-usage

angular 사용법 공부

https://www.notion.so/2021-01-27-37069b24837d4a0686a5465dd778a5c8 (업데이트됨)

- 다음 angular 지시자 상세 사용법 정리 및 예제 테스트
  - input
  - input[checkbox]
  - input[radio]
  - input[text]
  - ngChecked
  - a
  - ngHref

- 다음 요소들에 대한 상세한 비교, 작동방식 차이 학습 및 정리
  - onChange와 ng-change,
  - pattern vs ng-pattern,
  - value vs ng-value,
  - ng-checked vs ng-model,
  - ng-watch vs ng-changed,
  - html-a vs angular-a

---

## input

HTML input 엘리먼트 컨트롤이다.

`ngModel`과 같이 사용하여 데이터 바인딩, 입력 상태 제어, validation의 기능들을 제공한다.

- `[required]` : 입력값이 비었을 경우 required 에러 키를 설정한다
- `[ng-required]` : 값이 참일 경우 required 속성을 설정한다.
- `[ng-pattern]` : 정규표현식 검사
- `[ng-change]` : `$scope` 값이 변화될 때 trigger
- `[ng-trim=true]` : 자동 공백제거 여부 설정. `input[type=password]`에 대해서는 무시됨.

사용법:

```html
<input
ng-model="string"
[name="string"]
[required="string"]
[ng-required="boolean"]
[ng-minlength="number"]
[ng-maxlength="number"]
[ng-pattern="string"]
[ng-change="string"]
[ng-trim="boolean"]/>
```

## input[checkbox]

- `ngModel`: 바인딩 대상
- `[name]`: 폼에서 속성 이름
- `[ngTrueValue]`: 선택될 경우 표현식 값
- `[ngFalseValue]`: 해제될 경우 표현식 값
- `[ngChange]`: 변경될 경우의 실행 표현식 값

```html
<input type="checkbox"
       ng-model="string"
       [name="string"]
       [ng-true-value="expression"]
       [ng-false-value="expression"]
       [ng-change="string"]>
```

## input[radio]

- `ngModel` : 바인딩 대상
- `value` : 체크되었을 때의 `ngModel` 값, 문자열만 지원
- `[name]` : 폼에서 속성 이름
- `[ngChange]` : 변경될 경우의 실행 표현식
- `ngValue` : 체크되었을 때의 `ngModel` 값, 객체 지원

```html
<script>
  angular.module('radioExample', [])
    .controller('ExampleController', ['$scope', function($scope) {
      $scope.color = {
        name: 'blue'
      };
      $scope.specialValue = {
        "id": "12345",
        "value": "green"
      };
    }]);
</script>
<form name="myForm" ng-controller="ExampleController">
  <label>
    <input type="radio" ng-model="color.name" value="red">
    Red
  </label><br/>
  <label>
    <input type="radio" ng-model="color.name" ng-value="specialValue">
    Green
  </label><br/>
  <label>
    <input type="radio" ng-model="color.name" value="blue">
    Blue
  </label><br/>
  <code>color = {{color.name | json}}</code><br/>
 </form>
 Note that `ng-value="specialValue"` sets radio item's value to be the value of `$scope.specialValue`.
```

## input[text]

- `ngModel`:바인딩 대상
- `[name]`: 폼 속성 이름
- `[required]`: 필수여부
- `[ngRequired]`: 동적 필수여부
- `[ngMinlength]`: 최소 길이
- `[ngMaxlength]`: 최대 길이
- `[pattern]`: 문자열 regex 검사 패턴
- `[ngPattern]`: 동적 regex 검사 패턴
- `[ngChange]`: 변경시 발생 이벤트
- `[ngTrim = true]`: 자동 trim 여부

```html
<script>
  angular.module('textInputExample', [])
    .controller('ExampleController', ['$scope', function($scope) {
      $scope.example = {
        text: 'guest',
        word: /^\s*\w*\s*$/
      };
    }]);
</script>
<form name="myForm" ng-controller="ExampleController">
  <label>Single word:
    <input type="text" name="input" ng-model="example.text"
           ng-pattern="example.word" required ng-trim="false">
  </label>
  <div role="alert">
    <span class="error" ng-show="myForm.input.$error.required">
      Required!</span>
    <span class="error" ng-show="myForm.input.$error.pattern">
      Single word only!</span>
  </div>
  <code>text = {{example.text}}</code><br/>
  <code>myForm.input.$valid = {{myForm.input.$valid}}</code><br/>
  <code>myForm.input.$error = {{myForm.input.$error}}</code><br/>
  <code>myForm.$valid = {{myForm.$valid}}</code><br/>
  <code>myForm.$error.required = {{!!myForm.$error.required}}</code><br/>
 </form>
```

## ngChecked

- `ngChecked` : 표현식이 참이면, 해당 엘리먼트의 `checked` 속성이 참이 된다.

```html
<label>Check me to check both: 
  <input type="checkbox" ng-model="leader">
</label>
<br/>
<input id="checkFollower" type="checkbox" ng-checked="leader" aria-label="Follower input">
```

## a

href 속성이 비었을 때 기본 html a 태그와 동작이 다르다.

동적으로 a 태그를 위한 `href` 속성을 만들 때에는 `ngHref` 를 이용한다.

## ngHref

앵귤러가 `a` 태그의 `href` 값 내부의 표현식을 바꾸기 전에 유저가 링크를 클릭할 때 링크가 깨지는 문제를 막기 위함.

```html
<!-- 아래는 잘못됨 -->
<a href="http://www.gravatar.com/avatar/{{hash}}">link1</a>
<!-- 아래와 같이 사용 -->
<a ng-href="http://www.gravatar.com/avatar/{{hash}}">link1</a>
```

- `ngHref` : 템플릿을 포함하는 문자열

## comparison

onChange와 ng-change 차이??
- ng-change는 변경마다 매번 실행됨!

pattern vs ng-pattern
- ng-pattern에서는 expression 사용 '가능'
  - 문자열로 써도 된다

value vs ng-value
- ng-value는 ng-pattern과는 달리, 무조건 scope 값을 참조한다.
- 없으면 빈값.

ng-checked vs ng-model
- ng-checked로는 스코프 값이 안바뀐다! (변경시 가져오기만 한다.)

ng-watch vs ng-changed
- watch는 스코프값이 변경 될때마다 실행 (많이쓰면 성능 영향)
- watch는 변수 확인용으로 사용 가능

html-a vs angular-a
- 기존 a태그는 빈 href 태그 누르면 리로딩되는데, angular-a는 비어있

## refs

- [AngularJS doc](https://docs.angularjs.org/api)

## tags

  \#nodejs, \#javascript, \#ecmascript, \#js, \#angularjs, \#study

---