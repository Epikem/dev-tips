# 2021-02-01

# angular-practice

angular 사용법 공부

(3일 리뷰 준비)

---

## 사용자 정의 필터

- 모듈에 `.filter(...)` 함수를 이용하여 사용자 정의 필터 추가 가능
    - 내부적으로 `filterProvider` 사용
    - 필터 함수를 리턴하는 함수 작성, 첫 번째 인자가 필터 입력이고, 이후 인자는 매개변수이다
- 필터 함수는 순수 함수여야 한다 (상태 필요하면 모델로 꺼내서 순수 함수로 만들기)
- 이름에 `-`이나 `.` 은 허용되지 않는다 (표현식 이름 규칙과 동일)

### 사용법

```jsx

angular
  .module('core')
	.controller('FilterController', ['$scope', function($scope) {
	  $scope.checked = true
	}])

	.filter('checkmark', function(){
	  return function(input, colored){
	    if(colored){   // colored is truthy
	      console.log('colored')
	      return input ? '\u2705' : '\u274c'
	    }
	    return input ? '\u2713' : '\u2718'
	  }
	})
```

```html
<div ng-controller="FilterController">
    <p>
      checked
      <input type="checkbox" name="checked" id="checked" ng-model="checked">
    </p>
    <p>
      colored
      <input type="checkbox" name="colored" id="colored" ng-model="colored">
    </p>
    checkmark filter: {{ checked | checkmark:colored }}
  </div>
```

참조

- [https://docs.angularjs.org/tutorial/step_11](https://docs.angularjs.org/tutorial/step_11)
- [https://docs.angularjs.org/guide/filter#creating-custom-filters](https://docs.angularjs.org/guide/filter#creating-custom-filters)

## $http

- `XMLHttpRequest` 객체나 `JSONP` 를 통해 원격 HTTP 서버와의 통신 기능을 제공하는 AngularJS 코어 서비스
- `$q` 서비스로 제공되는 `deferred, promise` api에 기반함. (es6 promise와 같은것이 아니다)
- 캐싱을 사용할 수 있다 (`GET, JSONP` 만 지원)
- 단축 명령이 제공된다

### 사용법

```jsx
.controller('HTTPController', ['$http', function($http) {
  $http({
    method: 'POST',
    data: {asd:'fds'},
    url: 'https://httpbin.org/post'
  }).then(res=>{
    console.log(res)
  }).catch(err=>{
    console.error(err)
  })
}])
```

위와 같이 유일한 `configurationObject` 객체에 `method, url, headers, cache, data` 등 http 요청 정보 및 설정 정보를 설정하여 사용한다

참조

- [https://docs.angularjs.org/api/ng/service/$q#the-deferred-api](https://docs.angularjs.org/api/ng/service/$q#the-deferred-api)
- [https://docs.angularjs.org/api/ng/service/$q](https://docs.angularjs.org/api/ng/service/$q)
- [https://docs.angularjs.org/api/ng/service/$http#usage](https://docs.angularjs.org/api/ng/service/$http#usage)

## scope 상속

[https://docs.angularjs.org/guide/scope](https://docs.angularjs.org/guide/scope)

- 하위 스코프는 `child scope`이거나 `isolate scope`이다.
- `child scope`는 부모 스코프의 속성을 프로토타이핑을 통해 상속받으나, `isolate scope`는 그렇지 않다.
- 스코프는 표현식이 계산되는 문맥을 제공한다.
- 스코프는 컨트롤러와 뷰 사이를 잇는 역할을 한다. 그러나 컨트롤러와 뷰는 서로 모른다. 이는 테스팅에 이점이 있다.
- 표현식을 계산할 때, 현재 스코프에서 찾지 못하면 루트 스코프까지 올라가면서 찾는다.
- 스코프가 붙는 엘리먼트에 `ng-scope` css 속성이 붙는다
- `ng-controller`, `ng-repeat` 같은 지시자는 새로운 스코프를 만든다
- 스코프 이벤트 전파는 `broadcast` 를 통해 하위에 전파하거나, `emit` 을 통해 부모에 전파할 수 있다

### 예제

```html
<div ng-controller="ScopeInheritanceExampleController">
  <h2>ScopeInheritanceExampleController</h2>
  <p>nestedScopeValue : {{nestedScopeValue}}</p>
  <p>parentScopeValue: {{parentScopeValue}}</p>
  <p>notFoundScopeValue: {{notFoundScopeValue}}</p>

  <div ng-controller="ScopeInheritanceExampleNestedController">
    <h3>ScopeInheritanceExampleNestedController</h3>
    <p>nestedScopeValue : {{nestedScopeValue}}</p>
    <p>parentScopeValue: {{parentScopeValue}}</p>
    <p>notFoundScopeValue: {{notFoundScopeValue}}</p>
  </div>
</div>
```

```jsx
.controller('ScopeInheritanceExampleController', function($scope) {
  $scope.parentScopeValue = 'parent'
})

.controller('ScopeInheritanceExampleNestedController', function($scope) {
  $scope.nestedScopeValue = 'nested'
})
```

## $rootScope

- 앱의 최상위 스코프
- 모든 앱에 단일하게 존재해야하지만, 하위에 임의의 스코프들을 가질 수 있다
- 

## refs

## tags

\#nodejs, \#javascript, \#ecmascript, \#js, \#angularjs, \#study

---