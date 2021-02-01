# 2021-01-29

# angular-practice

angular 사용법 공부

(29일 리뷰 준비)

---

## ngClass

css 클래스를 동적으로 설정하기 위해 사용

다음 세가지 사용법으로 나뉨,

1. 표현식이 문자열로 계산되면, 공백으로 구분된 클래스 이름들로 적용됨
2. 표현식이 객체로 계산되면, 각 키가 클래스 이름, 값이 true/false를 결정
3. 표현식이 배열로 계산되면, 각 원소가 1번에 해당하거나 2번에 해당

표현식이 바뀌면, 이전 클래스는 제거되고 새로 클래스가 추가된다 (매 번 재계산한다는 것 같다)

주의: 클래스 속성에서 interpolation을 사용해서는 안 된다

사용법:

```html
<!-- 1. attribute -->
<any
	ng-class="expression">
...
</any>
<!-- 2. css class -->
<any class="ng-class: expression;"> ... </any>

```

예제:

```jsx
<h2>ng-class</h2>
<div>
  <p ng-class="{orange: orange, large: important, 'has-error': error}">Map Syntax Example</p>
  <label>
    <input type="checkbox" ng-model="orange">
    orange (apply "orange" class)
  </label><br>
  <label>
    <input type="checkbox" ng-model="important">
    important (apply "large" class)
  </label><br>
  <label>
    <input type="checkbox" ng-model="error">
    error (apply "has-error" class)
  </label>
  <hr>
  <p ng-class="style">Using String Syntax</p>
  <input type="text" ng-model="style" placeholder="Type: bold strike red" aria-label="Type: bold strike red">
  <hr>
  <p ng-class="[style1, style2, style3]">Using Array Syntax</p>
  <input ng-model="style1" placeholder="Type: bold, strike or red" aria-label="Type: bold, strike or red"><br>
  <input ng-model="style2" placeholder="Type: bold, strike or red" aria-label="Type: bold, strike or red 2"><br>
  <input ng-model="style3" placeholder="Type: bold, strike or red" aria-label="Type: bold, strike or red 3"><br>
  <hr>
  <p ng-class="[style4, {orange: warning}]">Using Array and Map Syntax</p>
  <input ng-model="style4" placeholder="Type: bold, strike" aria-label="Type: bold, strike"><br>
  <label><input type="checkbox" ng-model="warning"> warning (apply "orange" class)</label>
</div>
<style>
  .strike {
    text-decoration: line-through;
  }

  .bold {
    font-weight: bold;
  }

  .red {
    color: red;
  }

  .has-error {
    color: red;
    background-color: yellow;
  }

  .orange {
    color: orange;
  }

  .large {
    font-size: large;
  }
</style>
```

### animations

다음 애니메이션들이 발생한다:

- `addClass` : 클래스가 요소에 적용되기 직전
- `removeClass`: 클래스가 요소에서 삭제되기 직전
- `setClass`:클래스가 추가, 삭제되기 직전?

정확한 사용법 모르겠다. 예제에서 안나옴.

## ngStyle

css style을 html element에 동적으로 적용하게 한다.

`ngClass`처럼 ngStyle을 같이 사용할 때 interpolation을 사용하면 안 된다. (정확한 이유?)

사용법: 

`ngClass`처럼 attribute나 class로 사용가능.

표현식으로 참조된 객체의 키-값 쌍이 css 스타일 이름-값으로 적용된다.

객체 키로 사용할 수 없는 css 스타일 이름은 `''` 로 감싸야 한다.

ex: `'background-color'`

예제:

```html
<input type="button" value="set color" ng-click="myStyle={color:'red'}">
<input type="button" value="set background" ng-click="myStyle={'background-color':'blue'}">
<input type="button" value="clear" ng-click="myStyle={}">
<br/>
<span ng-style="myStyle">Sample Text</span>
<pre>myStyle={{myStyle}}</pre>
```

ngClass는 문자열 객체가 공백 분리된 클래스 나열이라면, ngStyle은 스타일 속성-값의 조합을 가진 객체이다.

## ngDisabled

표현식의 값이 참으로 판단되면 `disabled` 속성을 element에 설정한다.

예제:

```html
<label>Click me to toggle: <input type="checkbox" ng-model="checked"></label><br/>
<button ng-model="button" ng-disabled="checked">Button</button>
```

## ngShow

표현식 값에 따라 'css를 이용하여' element를 숨기거나 보여준다.

내부적으로 `.ng-hide` 클래스를 세팅/해제하여 작동하는데, `.ng-hide` 클래스는 `!important` 플래그를 사용한다.

오버라이딩?

깜빡임 문제?

사용법:

```html
<!-- element -->
<ng-show ng-show="expression">
...
</ng-show>
<!-- attribute -->
<any ng-show="expression">
...
</any>
```

애니메이션?

예제:

```jsx
<div>
Show: <input type="checkbox" ng-model="checked" aria-label="Toggle ngShow"><br />
<div class="check-element animate-show-hide" ng-show="checked">
  I show up when your checkbox is checked.
</div>
</div>

```

## ngHide

- `ngShow`와 마찬가지로 `.ng-hide` 클래스를 추가/제거하여 동작한다.

예제:

```jsx

<div>
Hide: <input type="checkbox" ng-model="checked" aria-label="Toggle ngHide"><br />
<div class="check-element funky-show-hide" ng-hide="checked">
  I hide when your checkbox is checked.
</div>
</div>

<script>
.animate-show-hide.ng-hide {
  opacity: 0;
}

.animate-show-hide.ng-hide-add,
.animate-show-hide.ng-hide-remove {
  transition: all linear 0.5s;
}

.check-element {
  border: 1px solid black;
  opacity: 1;
  padding: 10px;
}
</script>
```

## ngIf

- 표현식 값에 따라 element를 DOM에서 지우거나, 복사본을 다시 DOM에 추가하거나 한다
- 다시 만들때 스코프도 다시 만들어진다.
- `ngModel` 을 `ngIf` 아래에서 쓰면 자식에서의 변경이 부모 스코프를 가린다?
- 컴파일? 당시의 기준으로 복제하여 추가되므로, 이후 `addClass` 등의 변경이 가해져도 다시 추가하면 컴파일 상태로 돌아간다
- 이 지시자는 새로운 스코프를 만든다

사용법:

```html
<any ngIf="expression">
...
</any>
```

예제:

```jsx
<label>Click me: <input type="checkbox" ng-model="checked" ng-init="checked=true" /></label><br/>
Show when checked:
<span ng-if="checked" class="animate-if">
  This is removed when the checkbox is unchecked.
</span>

<style>
.animate-if {
  background:white;
  border:1px solid black;
  padding:10px;
}

.animate-if.ng-enter, .animate-if.ng-leave {
  transition:all cubic-bezier(0.250, 0.460, 0.450, 0.940) 0.5s;
}

.animate-if.ng-enter,
.animate-if.ng-leave.ng-leave-active {
  opacity:0;
}

.animate-if.ng-leave,
.animate-if.ng-enter.ng-enter-active {
  opacity:1;
}
</style>

```

## ngSwitch

- `ng-switch` 표현식 값에 따라 `ng-switch-when` 을 표시한다
- 표현식과 매치되는 `when` 이 없으면 기본 `ng-switch-default` 가 표시된다.
- `ng-switch-when-separator` 를 써서 여러 조건을 or로 묶을 수 있다.
- ng-switch + `on` 을 써도 같은 효과
- ngIf와 마찬가지로 DOM을 건드린다.

## ngRepeat

- 배열 아이템마다 템플릿을 찍어낸다
- 각 템플릿이 고유 스코프를 가진다
- `$index` 가 아이템 인덱스나 키로 설정된다?
- 로컬 스코프의 특수 속성들을 사용 가능하다:
    - `$index, $first, $middle, $last, $even, $odd`
- 객체를 순회하는 것도 가능하나, 순서가 보장되지 않는다.

### 변경 트래킹, 중복 처리

- `ngRepeat` 는 `$watchCollection` 을 이용하여 컬렉션 변경을 감지한다.
- 컬렉션의 모든 아이템과 해당하는 DOM 엘리먼트를 추적하여 그리기 회수를 최소화한다.
- 아이템을 나타내는 유일 식별키가 있다면 해당 키로 추적하는 것이 성능에 좋다
- DOM 요소가 재사용될 때, 스코프가 업데이트되므로 활성 바인딩?이 자동으로 업데이트되지만, 다음 요소는 업데이트되지 않는다:
    - 지시자는 재컴파일되지 않는다
    - 반복 템플릿의 일회성 표현식은 업데이트되지 않는다

- [x]  예제추가
- [ ]  `$watchCollection`

```html
<div ng-controller="repeatController">
  <ol>
    <li>When you click "Update Age", only the first list updates the age, because all others have
    a one-time binding on the age property. If you then click "Copy", the current friend list
    is copied, and now the second list updates the age, because the identity of the collection items
    has changed and the list must be re-rendered. The 3rd and 4th list stay the same, because all the
    items are already known according to their tracking functions.
    </li>
    <li>When you click "Remove First", the 4th list has the wrong age on both remaining items. This is
    due to tracking by $index: when the first collection item is removed, ngRepeat reuses the first
    DOM element for the new first collection item, and so on. Since the age property is one-time
    bound, the value remains from the collection item which was previously at this index.
    </li>
  </ol>

  <button ng-click="removeFirst()">Remove First</button>
  <button ng-click="updateAge()">Update Age</button>
  <button ng-click="copy()">Copy</button>
  <br><button ng-click="reset()">Reset List</button>
  <br>
  <code>track by $id(friend)</code> (default):
  <ul class="example-animate-container">
    <li class="animate-repeat" ng-repeat="friend in friends">
      {{friend.name}} is {{friend.age}} years old.
    </li>
  </ul>
  <code>track by $id(friend)</code> (default), with age one-time binding:
  <ul class="example-animate-container">
    <li class="animate-repeat" ng-repeat="friend in friends">
      {{friend.name}} is {{::friend.age}} years old.
    </li>
  </ul>
  <code>track by friend.name</code>, with age one-time binding:
  <ul class="example-animate-container">
    <li class="animate-repeat" ng-repeat="friend in friends track by friend.name">
      {{friend.name}}  is {{::friend.age}} years old.
    </li>
  </ul>
  <code>track by $index</code>, with age one-time binding:
  <ul class="example-animate-container">
    <li class="animate-repeat" ng-repeat="friend in friends track by $index">
      {{friend.name}} is {{::friend.age}} years old.
    </li>
  </ul>
</div>
<script>
angular.module('ngRepeat', ['ngAnimate']).controller('repeatController', function($scope) {
  var friends = [
    {name:'John', age:25},
    {name:'Mary', age:40},
    {name:'Peter', age:85}
  ];

  $scope.removeFirst = function() {
    $scope.friends.shift();
  };

  $scope.updateAge = function() {
    $scope.friends.forEach(function(el) {
      el.age = el.age + 5;
    });
  };

  $scope.copy = function() {
    $scope.friends = angular.copy($scope.friends);
  };

  $scope.reset = function() {
    $scope.friends = angular.copy(friends);
  };

  $scope.reset();
});
</script>

```

## $filter

1. 서비스 필터:

[https://docs.angularjs.org/api/ng/filter](https://docs.angularjs.org/api/ng/filter)

- 보여지는 데이터를 포매팅하기위해 사용한다
- 뷰 템플릿, 컨트롤러, 서비스에서 사용 가능하다

기본 사용방법:

```html
{{ expression [| filter_name[:parameter_value] ... ] }}
```

예제:

```html
<script>
angular.module('filterExample', [])
.controller('MainCtrl', function($scope, $filter) {
  $scope.originalText = 'hello';
  $scope.filteredText = $filter('uppercase')($scope.originalText);
});
</script>
<div ng-controller="MainCtrl">
 <h3>{{ originalText }}</h3>
 <h3>{{ filteredText }}</h3>
</div>
```

2. 모듈 필터

[https://docs.angularjs.org/api/ng/filter/filter](https://docs.angularjs.org/api/ng/filter/filter)

- 배열에서 특정 조건을 만족하는 원소들을 골라 새 배열로 리턴한다
- 기본 필터들이 지원되며, 커스텀 필터도 만들 수 있다
- `strict` 옵션을 걸면 정확히 일치한 것만 검색한다.

사용법: 템플릿이나 자바스크립트에서 사용 가능하다

1. `{{ filter_expression | filter : expression : comparator : anyPropertyKey}}`
2. `$filter('filter')(array, expression, comparator, anyPropertyKey)`

예제:

```html
<div>
  <div ng-init="issues = [{title:'board bugfix', phone:'555-1276'},
  {title:'cors issue', phone:'800-BIG-MARY'},
  {title:'async style', phone:'555-4321'},
  {title:'search-text', phone:'555-5678'},
  {title:'sort problem', phone:'555-8765'}]"></div>

  <label>Search: <input ng-model="searchText"></label>
  <table id="searchTextResults">
    <tr>
      <th>Title</th>
      <th>Phone</th>
    </tr>
    <tr ng-repeat="issue in issues | filter:searchText">
      <td>{{issue.title | uppercase}}</td>
      <td>{{issue.phone}}</td>
    </tr>
  </table>
  <hr>
  <label>Any: <input ng-model="search.$"></label> <br>
  <label>Title only <input ng-model="search.title"></label><br>
  <label>Phone only <input ng-model="search.phone"></label><br>
  <label>Equality <input type="checkbox" ng-model="strict"></label><br>
  <table id="searchObjResults">
    <tr>
      <th>Title</th>
      <th>Phone</th>
    </tr>
    <tr ng-repeat="issueObj in issues | filter:search:strict">
      <td>{{issueObj.title}}</td>
      <td>{{issueObj.phone}}</td>
    </tr>
  </table>
</div>

```

플러스

- show vs if
    - ng-show는 css를 통해 동작하고, ng-if는 DOM을 직접 바꾼다.
- $filter : 뷰,코드 차이

## 미니과제

repeat, input으로 필터링된 테이블 만들기, 데이터 length등

[https://kamang-it.tistory.com/entry/Web동일-출처-정책-CORS-도대체-뭘까](https://kamang-it.tistory.com/entry/Web%EB%8F%99%EC%9D%BC-%EC%B6%9C%EC%B2%98-%EC%A0%95%EC%B1%85-CORS-%EB%8F%84%EB%8C%80%EC%B2%B4-%EB%AD%98%EA%B9%8C)

## refs

[AngularJS](https://docs.angularjs.org/api/ng/input/input%5Btext%5D)

인라인 스타일: DOM에 직접 스타일먹이면 클래스 스타일 안먹는다. `ngStyle`은 인라인으로 들어가므로 `ngClass`를 덮어쓸수있다. 주의.

ng-hide: `display: none !important;` 으로 설정한다.

## feedback

ngIf : DOM 엘리먼트 재생성하므로 비교적 비싸다

그래도 DOM에서 없애야 할 때 쓴다

trackBy는 값이 안바뀌면 다시 안그린다. 키 값이 중복이 있으면 안된다.

원래는 `watchCollection` 은 일부만 변경되어도 다 그린다? 그러므로 trackBy쓰는것이 성능에 좋다.

변경된 것에 대해서만 DOM을 그린다.

앵귤러 내부 필터: 전문검색 (객체 내부까지 전체 검색)

## tags

#nodejs, #javascript, #ecmascript, #js, #angularjs, #study

---