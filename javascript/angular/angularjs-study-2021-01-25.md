# angularjs-study-2021-01-25

angular js 사용법 공부

----

- [목적](#목적)
- [셋업](#셋업)
- [ng-href](#ng-href)
- [scope](#scope)
  - [스코프 라이프사이클](#스코프-라이프사이클)
- [promise 패턴](#promise-패턴)
  - [기초 사용법](#기초-사용법)
- [ng-app](#ng-app)
  - [사용법](#사용법)
- [angular.boostrap](#angularboostrap)
- [angular.module()](#angularmodule)
  - [사용법](#사용법-1)
- [ngBind](#ngbind)
- [ngModel](#ngmodel)
  - [복잡한 모델 (객체, 배열)](#복잡한-모델-객체-배열)
- [ngClick](#ngclick)
  - [예제](#예제)
- [refs](#refs)
- [tags](#tags)

## 목적
- 각 지시자 학습
- 옵션 익히기

## 셋업
[온라인 환경](https://stackblitz.com/)이나 로컬 셋업이 가능하다.
https://angular.io/guide/setup-local

다음 명령들로 로컬 셋업
```sh
npm install -g @angular/cli # cli 설치
ng new my-app # 프로젝트 생성
```
그리고 다음 명령으로 데모 앱 실행: `ng serve --open`

1. 컴포넌트

컴포넌트는 다음 세 가지 요소로 이루어진다:
- 데이터와 기능을 다루는 컴포넌트 클래스
- UI를 결정하는 HTML
- 외관을 결정하는 스타일


## ng-href

https://docs.angularjs.org/api/ng/directive/ngHref

링크의 href 내에 angular 표현식을 사용할 때 쓴다.


## scope
https://docs.angularjs.org/guide/scope

- 앱 모델을 참조하는 객체
- 표현식의 실행 문맥
- DOM 구조를 따라 계층 구조로 되어 있음
- 표현식을 감시하거나, 이벤트를 전파할 수 있음.

- 스코프는 모델 변경을 감시할 수 있는 api (`$watch`) 제공
- 컨트롤러, 서비스, 이벤트 핸들러 등 외부 입력으로부터 모델 변경 전파를 통해 뷰를 업데이트할 수 있는 api (`$apply`) 제공
- 스코프를 중첩시켜 공통된 모델 속성을 제공하면서 동시에 접근을 제한할 수 있다.
- 중첩 스코프는 `child scope`이거나 `isolate scope`이다.
- `child scope`는 부모 스코프의 속성을 상속받으나, `isolate scope`는 그렇지 않다.
- 스코프는 표현식이 계산되는 문맥을 제공한다.

- 스코프는 컨트롤러와 뷰 사이를 잇는 역할을 한다. 그러나 컨트롤러와 뷰는 서로 모른다. 이는 테스팅에 이점이 있다.

예제:
```js
angular.module('scopeExample', [])
.controller('MyController', ['$scope', function($scope) {
  $scope.username = 'World';

  $scope.sayHello = function() {
    $scope.greeting = 'Hello ' + $scope.username + '!';
  };
}]);

```


### 스코프 라이프사이클
1. root scope가 $injector를 통해 생성된다. 템플릿 링킹 과정에서 directives에 의해 하위 스코프가 생성된다.
2. 템플릿 링킹 과정에서 스코프에 $watch를 등록한다. 이 $watch들이 모델 값을 DOM에 전파하는데 쓰인다.
3. 모델 변화가 감지되면 $apply함수가 호출된다. 동기적 작업이나, $http, $timeout, $interval을 이용한 비동기 작업에서는 엔진에서 암시적으로 적용하므로 필요하지 않다.
4. $apply가 끝나면, $digest 사이클이 루트부터 모든 하위 스코프까지 실행된다. 모델 변경이 있었는지 확인하여 $watch 표현식이나 함수를 업데이트한다.
5. 스코프가 더이상 쓰이지 않으면, scope.$destroy api를 통해 $digest 사이클에서 제외되며, 향후 가비지 컬렉팅된다.

- dom에 표현할 것만 스코프에 쓰고, 그 외의 변수 함수들은 스코프에 하지 않고 그냥 선언한다.

## promise 패턴

Promise는 자바스크립트 비동기 처리를 위한 객체입니다.

- Pending, Fulfilled, Rejected의 세 가지 상태를 가짐
  - 생성 시 pending 상태,
  - resolve() 호출시 fulfilled,
  - reject() 호출시 rejected 상태가 된다
- then을 이용하여 1개 이상의 프로미스 체이닝 가능
- 에러 처리 방법:
  - 1. catch를 이용하여 예외 처리 (권장)
  - 2. then()의 두 번째 인수 활용

* resolve, reject중 먼저 실행된 것이 적용된다. (상태 다이어그램대로)
* promise가 리턴되어야 then으로 체이닝 가능.
* async+await=promise+generator

### 기초 사용법

```js
function fetchData(cb){
  return new Promise(function(resolve, reject){
    $.get('/data', function(response){
      
      resolve(response)
    })
  })  
}

fetchData().then(function(data){
  console.log(data)
}).catch(function(error){
  console.error(error)
})
```

- https://stackoverflow.com/questions/35135110/jquery-ajax-with-es6-promises


## ng-app

AngularJS 앱을 자동으로 초기화해주는 지시자.
보통 문서 내용 최상단에 넣는다.

### 사용법

```html
<ng-app
  ng-app="angular.Module"
  [ng-strict-di="boolean"]>
...
</ng-app>
```

- strictDi : 

## angular.boostrap

수동으로 앱을 초기화할때 쓰이는 함수.

**ng-app vs angular.bootstrap 차이 알기!** (중요)
  * dom 로드 후인가 / 레디 상태인가.
* 전처리가 필요한 상황 등의 경우 후자 사용 (앱이 먼저 돌아가서 작업이 필요할때)

예제:
```html
<!doctype html>
<html>
<body>
<div ng-controller="WelcomeController">
  {{greeting}}
</div>

<script src="angular.js"></script>
<script>
  var app = angular.module('demo', [])
  .controller('WelcomeController', function($scope) {
      $scope.greeting = 'Welcome!';
  });
  angular.bootstrap(document, ['demo']);
</script>
</body>
</html>
```



## angular.module()

앱 모듈을 생성, 등록, 접근할때 쓰이는 글로벌 함수.
- 1개의 파라미터로 호출하면 기존 모듈을 가져오고, 2개 이상의 파라미터로 호출하면 새 모듈을 생성한다.
- 모듈은 서비스, 지시자, 컨트롤러, 필터, 설정 정보의 조합이다.

### 사용법
`angular.module(name, [requires], [configFn]);`
- name: 만들거나 가져올 모듈 이름
- requires?: 
  - 없으면 기존 모듈 가져옴
  - 있으면 새 모듈 생성??
- configFn:
  - 추가 설정

예제:
```js
// Create a new module
var myModule = angular.module('myModule', []);

// register a new service
myModule.value('appName', 'MyCoolApp');

// configure existing services inside initialization blocks.
myModule.config(['$locationProvider', function($locationProvider) {
  // Configure existing providers
  $locationProvider.hashPrefix('!');
}]);
```

## ngBind
https://docs.angularjs.org/api/ng/directive/ngBind

주어진 표현식의 값으로 html 엘리먼트의 내용을 채워주는 지시자.
표현을 위한 것이므로, input, select, textarea에서는 사용불가.

`{{ }}` 표현식보다 성능상 낫다고 한다. (http://curlybrackets.com/posts/43030/difference-between-expression-and-ng-bind)

ngBind

예제:
```html
<script>
  angular.module('bindExample', [])
    .controller('ExampleController', ['$scope', function($scope) {
      $scope.name = 'Whirled';
    }]);
</script>
<div ng-controller="ExampleController">
  <label>Enter name: <input type="text" ng-model="name"></label><br>
  Hello <span ng-bind="name"></span>!
</div>
```

## ngModel
https://docs.angularjs.org/api/ng/directive/ngModel

`input`, `select`, `textarea`를 스코프의 속성에 바인딩한다.
`ngModel`은 다음을 제공한다:
- 뷰와 모델 바인딩
- validation
- 컨트롤 상태 제어
- 관련 css와 애니메이션 제어
- 부모 폼에 컨트롤 등록

* 현재 스코프에 해당 속성이 없을 경우, `ngModel`은 해당 속성을 암시적으로 생성하고 스코프에 등록한다.

- 사용자 입력의 경우 model 사용.

### 복잡한 모델 (객체, 배열)

- 기본적으로 `ngModel`은 참조로 작동하므로, 속성이나 원소 변경으로는 업데이트가 일어나지 않는다.
- `$watchCollection`을 통해 원소를 감시할 수 있으나, 이것도 2단계 이상의 변경을 감지하지는 않는다.
  - (배열에서 원소의 속성만 변경하는 등.)

## ngClick
https://docs.angularjs.org/api/ng/directive/ngClick

엘리먼트가 클릭되었을 때의 동작 설정 기능 제공

`func($event)`로 이벤트 정보를 받을 수 있다.

### 예제
```html
<button ng-click="count = count + 1" ng-init="count=0">
  Increment
</button>
<span>
  count: {{count}}
</span>
```

## refs
- https://jins-dev.tistory.com/entry/AngularJS-%EC%97%90%EC%84%9C%EC%9D%98-Scope-%EC%9D%98-%EA%B0%9C%EB%85%90
- https://joshua1988.github.io/web-development/javascript/promise-for-beginners/
- [ngModel](https://docs.angularjs.org/api/ng/directive/ngModel)
- [ngClick](https://docs.angularjs.org/api/ng/directive/ngClick)
- [angular-bootstrap-process](https://docs.angularjs.org/guide/bootstrap)

## tags
  \#nodejs, \#javascript, \#ecmascript, \#js, \#node-event, \#study



----

 
