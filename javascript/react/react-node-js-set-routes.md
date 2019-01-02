# react-node-js-set-routes

리액트 노드 자바스크립트 라우팅 설정하기

----


- [desc](#desc)
- [inst](#inst)
  - [예시 :](#예시-)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc
- 자바스크립트 노드 리액트에서 라우팅 설정을 할 수 있다.

## inst
### 예시 :
  App.js 에서 라우터를 다음과 같이 설정한다 :
> 📂 App.js
```jsx
<Route path="/about/:name/:what" component={About}/>
<Route path="/about" component={About}/>
```

About.js의 코드가 다음과 같을 때
> 📂 About.js
```jsx
import React from 'react';
import queryString from 'query-string';

const About = ({location, match}) => {
  const query = queryString.parse(location.search);

  const detail = query.detail === 'true';

  return (
    <div>
    <h2>About {match.params.name}</h2>
    <p>second : {match.params.what}</p>
    {detail && 'detail : blahblah'}
    </div>
  );
};

export default About;
```

예를 들어 주소창에 `App/foo/barr?detail=true`를 적으면 `About` 컴포넌트는 `{location, match}`에 다음과 같은 정보를 받게 된다.
  `match.params.name`은 `foo`
  `match.params.what`은 `barr`
  `location.search = <쿼리 문자열, detail값=true>`

그런데 만약 `App/foo` 까지만 할 경우 `:what params`만 안 받고 `/about/:name/:what` 라우트로 받는 방식이 아니라, 아예 매치가 안되어서 다음 라우트인
 `/about` 으로 매치가 되고, `About` 컴포넌트는 `match.params`에 아무것도 없다.

```
About asddsd

second : ddddddddd
detail : blahblah
```
<!-- | Tables        | Are           | Cool  |
| ------------- | --------------| ----- |
| col 3 is      | right-aligned | $1600 |
| col 2 is      | centered      |   $12 |
| zebra stripes | are neat      |    $1 |
 -->


**이 아래 부분의 출처 : [velopert blog](#ref)**
>### 라우트 파라미터 읽기
>
> 라우트의 경로에 특정 값을 넣는 방법을 알아보겠습니다. 방법은 두가지가 있는데요, params 를 사용하는 것 과, query 를 사용하는 것 입니다.
>
> 라우트로 설정한 컴포넌트는, 3가지의 props 를 전달받게 됩니다:
>
> history 이 객체를 통해 push, replace 를 통해 다른 경로로 이동하거나 앞 뒤 페이지로 전환 할 수 있습니다.
> location 이 객체는 현재 경로에 대한 정보를 지니고 있고 URL 쿼리 (/about?foo=bar 형식) 정보도 가지고있습니다.
> match 이 객체에는 어떤 라우트에 매칭이 되었는지에 대한 정보가 있고 params (/about/:name 형식) 정보를 가지고있습니다.
>
> (Route에 component를 지정하는 그 경로 이후부터는 전부 그 컴포넌트가 match로서 받는다는 뜻으로 보인다. 근데 About에 라우터 설정하고 About/asd/asd2/asd3 으로 접속하면 match.params.name은 asd라고만 나온다.)
>
> ### URL 쿼리
>
> 리액트 라우터 v3 에서는 URL 쿼리를 해석해서 객체로 만들어주는 기능이 자체적으로 있었는데요, 쿼리를 파싱하는 방식은 여러가지가 있어서, 개발자들이 여러가지를 방식을 사용 할 수 있도록 이 기능을 더이상 내장하지 않습니다. 따라서 URL 쿼리를 해석하는것은 우리의 몫입니다.
>
> 쿼리를 해석하기 위해선, 라이브러리를 설치해주세요. 자체적으로 구현하는 방법도 있겠지만 라이브러리를 사용하는것이 훨씬 간편합니다.
>
> `$ yarn add query-string`
>
>
> ### 1-3. 라우트 이동하기
> Link 컴포넌트
>
> 앱 내에서 다른 라우트로 이동 할 때에는, 일반 `<a href...>foo</a>` 형식으로 하면 안됩니다. 왜냐하면, 이렇게하면 새로고침을 해버리기 때문이지요.
>
> 새로고침을 하기 위해선, 리액트 라우터에 있는 Link 컴포넌트를 사용해야합니다. 이 컴포넌트를 사용하면 페이지를 새로 불러오는걸 막고, 원하는 라우트로 화면 전환을 해줍니다.
>
>
> ### NavLink 컴포넌트
>
> NavLink 컴포넌트는 Link 랑 비슷한데요, 만약에 설정한 URL 이 활성화가 되면, 특정 스타일 혹은 클래스를 지정 할 수 있습니다.
> Route 를 지정 할 때 처럼, 중첩될수도 있는 라우트들은 exact 로 설정을 하셔야 합니다. 만약에 활성화 되었을 때 특정 클래스를 설정하고 싶다면 activeClassName 을 설정하시면 됩니다.


## dep
  - node, react, js

## ref
  - [velopert blog](https://velopert.com/3417)

## tags
  #node, #react, #js, #javascript, #ecmascript, #route, #web



----

 
