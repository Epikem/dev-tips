browserify-study
=====

----


- [title](#title)
- [소개](#소개)
- [모듈 로더 vs 번들러](#모듈-로더-vs-번들러)
- [설치](#설치)
- [사용법](#사용법)
  - [추가 사용법](#추가-사용법)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## title
- browserify 소개 및 사용법

## 소개
  - [자바스크립트 모듈 번들러](http://browserify.org/)

## 모듈 로더 vs 번들러

- js는 원래 모듈화 개념이 없었음
- 오픈소스여서 여러 방식으로 모듈화가 만들어짐
- 모듈 로더: 런타임에 스크립트 로드
  - 실행 시간에 클라이언트 사이드에서 필요할 때마다 js 요청
  - http 통신 부하가 발생
- 모듈 번들러: 빌드 시간에 스크립트를 묶음
  - 필요한 종속 등을 빌드 시간에 모두 묶어서 하나의 js로 만듬
  - 요즘은 webpack이 자주 쓰임

## 설치

- browserify는 보통 실행 도구로서 사용한다. 따라서 cli를 설치해야 한다.

- 다음 명령으로 browserify를 전역으로 설치한다:
  `npm install --global browserify`

- 그러면 터미널에서 `browserify` 명령을 실행할 수 있게 된다.

## 사용법

browserify는 `browserify` cli를 설치하여 종속 트리의 시작이 되는 메인 소스 js 파일을 지정하면 종속성들을 한데 묶어 결과 파일로 내보내도록 하는 기능을 제공한다.

다음과 같이 cli를 사용한다:

```
browserify main.js -o bundle.js
```

그러면 번들링 결과인 `bundle.js`를 출력하고, 필요한 html 파일에서 참조하여 사용하면 된다.

### 추가 사용법

- `-d` 옵션을 주어 source-map을 활성화 가능 (보통 개발할 때에만 source-map이 생성되도록 한다)

## dep
  - browserify
  - js

## ref
  - http://browserify.org/
  - https://kamang-it.tistory.com/entry/ModuleBundlerBrowserifyjs%EB%A5%BC-%ED%95%98%EB%82%98%EC%9D%98-%ED%8C%8C%EC%9D%BC%EB%A1%9C-%EB%AC%B6%EA%B8%B0-browserify%EC%84%A4%EC%B9%98-%EB%B0%8F-%EC%82%AC%EC%9A%A9%EB%B2%95
  - https://github.com/browserify/browserify-handbook

## tags
  \#javascript, \#ecmascript, \#js, \#browserify



   