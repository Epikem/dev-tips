# angularjs-study-2021-01-28

# angular-practice

angular 사용법 공부

(29일 리뷰 준비)

---

## ngClass

css 클래스를 동적으로 설정하기 위해 사용

다음 세가지 사용법으로 나뉨

1. 표현식이 문자열이면, 공백으로 구분된 클래스 이름들로 적용됨
2. 표현식이 객체이면, 각 키가 클래스 이름, 값이 true/false를 결정
3. 표현식이 배열이면, 각 원소가 1번에 해당하거나 2번에 해당

표현식이 바뀌면, 이전 클래스는 제거되고 새로 클래스가 추가된다 (매 번 재계산한다는 것 같다)

주의: 클래스 속성에서 interpolation을 사용해서는 안 된다.?

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

예제?:

## ngHide

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

## ngSwitch

- `ng-switch` 표현식 값에 따라 `ng-switch-when` 을 표시한다
- `ngInclude` 와 차이?
- 표현식과 매치되는 `when` 이 없으면 기본 `ng-switch-default` 가 표시된다.

## ngRepeat

- 배열 아이템마다 템플릿을 찍어낸다
- 각 템플릿이 고유 스코프를 가진다
- `$index` 가 아이템 인덱스나 키로 설정된다?
- 로컬 스코프의 특수 속성들을 사용 가능하다:
    - `$index, $first, $middle, $last, $even, $odd`
- 객체를 순회하여 찍어내는 것도 가능하나, 순서가 보장되지 않는다.

### 변경 트래킹, 중복 처리

- `ngRepeat` 는 `$watchCollection` 을 이용하여 컬렉션 변경을 감지한다.
- 컬렉션의 모든 아이템과 해당하는 DOM 엘리먼트를 추적하여 그리기 회수를 최소화한다.
- 아이템을 나타내는 유일 식별키가 있다면 해당 키로 추적하는 것이 성능에 좋다
- DOM 요소가 재사용될 때, 스코프가 업데이트되므로 활성 바인딩?이 자동으로 업데이트되지만, 다음 요소는 업데이트되지 않는다:
    - 지시자는 재컴파일되지 않는다
    - 반복 템플릿의 일회성 표현식은 업데이트되지 않는다

- [ ]  예제추가
- [ ]  `$watchCollection`

## $filter

[https://docs.angularjs.org/api/ng/filter](https://docs.angularjs.org/api/ng/filter)

- 보여지는 데이터를 포매팅하기위해 사용한다
- 뷰 템플릿, 컨트롤러, 서비스에서 사용 가능하다
- 기본 필터들이 지원되며, 커스텀 필터도 만들 수 있다

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

- [ ]  커스텀 필터 어떻게 등록?
- [ ]  어떻게 동작?

플러스

- show vs if
- $filter : 뷰,코드 차이

## 미니과제

repeat, input으로 필터링된 테이블 만들기, 데이터 length등

과제하다가 allow-origin 관련 에러 발생

[https://kamang-it.tistory.com/entry/Web동일-출처-정책-CORS-도대체-뭘까](https://kamang-it.tistory.com/entry/Web%EB%8F%99%EC%9D%BC-%EC%B6%9C%EC%B2%98-%EC%A0%95%EC%B1%85-CORS-%EB%8F%84%EB%8C%80%EC%B2%B4-%EB%AD%98%EA%B9%8C)

## refs

[AngularJS](https://docs.angularjs.org/api/ng/input/input%5Btext%5D)

## tags

#nodejs, #javascript, #ecmascript, #js, #angularjs, #study

---