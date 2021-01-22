gulp-usage
=====

----


- [title](#title)
- [desc](#desc)
  - [소개](#소개)
  - [사용법](#사용법)
    - [1. 설치](#1-설치)
    - [2. `gulp` 명령 실행](#2-gulp-명령-실행)
    - [3. 작업 구성](#3-작업-구성)
  - [api](#api)
    - [태스크 선언](#태스크-선언)
    - [series, parallel](#series-parallel)
    - [src, dest](#src-dest)
    - [glob](#glob)
    - [plugins](#plugins)
    - [watching](#watching)
    - [custom registries](#custom-registries)
- [inst](#inst)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## title
- gulp 소개 및 사용법

## desc

### 소개
  - [Node.js 기반 빌드 자동화 도구](https://zetawiki.com/wiki/Gulp)
  - 자바스크립트 작업 자동화 툴.
  - minify, style파일 컴파일, 파일 변경 감지 등 가능
  - 다양한 플러그인 제공

### 사용법

gulp는 `gulp` cli를 설치하고, 비동기 태스크들을 구성하여 실행할 수 있는 api를 제공하여 사용자가 자동화 스크립트를 쉽게 작성할 수 있도록 한다. 따라서 다음이 제공된다:
- gulp cli
  - gulpfile 실행
  - 태스크 구조 확인
  - ...
- gulp api
  - series, parallel : 태스크 실행 제어
  - src, dest : 입출력 스트림 제어
  - ...

사용자는 다음을 하여:
- cli 설치
- api를 사용하여 `gulpfile.js` 작성
다음을 할 수 있다:
- `gulp` 명령으로 `gulpfile.js`의 작업 실행

#### 1. 설치

- gulp는 보통 실행 도구로서 사용한다. 따라서 cli를 설치해야 한다.

- 다음 명령으로 gulp를 전역으로 설치한다:
  `npm install --global gulp-cli`

- 그러면 터미널에서 `gulp`명령으로 gulp를 실행할 수 있게 된다.

#### 2. `gulp` 명령 실행
  - `gulp` 명령을 실행하면 기본적으로 같은 폴더 내의 `gulpfile.js`를 찾아서 실행한다.
  - 해당 `gulpfile.js`의 기본(default) 태스크가 있을 경우 그것을 실행하고, 여러 태스크가 있을 경우 `gulp <taskname>`식으로 해당 태스크만 실행 가능하다. 

- 해당 `gulpfile.js`에 빌드 자동화 스크립트를 작성하게 된다.
- `gulpfile.js`는 기본적으로 다음과 같은 형태를 가진다.
- 기본 예제 폴더구조는 (e1) 참조

<details><summary markdown="span">gulfile.js</summary>

```js
const { series } = require('gulp');

// clean 함수는 내보내지 않았으므로 `gulp clean`으로 실행 불가 (private)
function clean(cb) {
  // body omitted
  cb();
}

// build 함수는 export했으므로 `gulp build`로 실행 가능 (public)
function build(cb) {
  // body omitted
  cb();
}

// `gulp build`로 실행
exports.build = build;
// 기본 `gulp`로 실행
exports.default = series(clean, build);
```

- `gulp --tasks` 명령으로 태스크 구조를 확인할 수 있다.

#### 3. 작업 구성

- gulp의 `series()`, `parallel()` api로 여러 작업이 어떻게 실행될지 구성할 수 있다.
- (e3-g1)처럼 임의 깊이로 작업을 구성할 수 있다.
- 각각의 태스크는 참조될 때마다 실행되므로, 태스크를 (e3-g2)와 같이 구성해서는 안 된다.

### api

#### 태스크 선언
  - 어떤 형태로든 비동기 함수여야 한다:
    - 콜백 함수: 콜백 파라미터 호출
      - 콜백 호출시 완료
        - `fs`등 api 함수 인자에 cb를 넘기는 방법 있음
      - 콜백에 에러 넘기면 실패
    - async/await
      - ...
    - EventEmitter: emit `finish`
    - child_process: 종료
    - observable: 무엇..?
  - 
#### series, parallel
  - 순차/병렬 태스크 실행
#### src, dest
  - src
    - glob으로 input 가져옴
      - 단일 또는 glob 배열을 입력받음
    - 버퍼링, 스트리밍, empty 세 가지 모드로 동작
      - 버퍼링: 기본 모드, 메모리로 파일 로드하여 처리. 대다수 플러그인이 해당 모드만 지원
      - 스트리밍: 대용량 파일 처리용. 
      - empty: 메타데이터용
  - pipe
    - `pipe`로 변환 가능
  - def
    - dest로 경로/스트림에 출력
#### glob
  - 플랫폼 무관 구분자는 `/`를 사용한다.
  - node.js의 `__dirname, __filename, process.cwd()`, path 모듈 등 사용하면 안 된다.
    - Windows에서 생성하는 `\\` 문자가 노드에서 구분자로 사용되므로 사용 불가?
  - 특수문자:
    - `*`: 단일 segment 매칭
    - `**`: 임의 segment 매칭
    - 제외: glob 배열에 `!`로 시작하는 원소를 추가
      - 폴더를 통째로 제외하려면 끝에 `/**`를 붙인다.
```js
['scripts/**/*.js', '!scripts/vendor/**']
```
#### plugins
  - 플러그인 목록 사이트: https://gulpjs.com/plugins/
  - Node Transform Stream 사용
  - gulp-if로 조건부 동작 가능
  - through2를 이용하여 인라인 플러그인 작성 가능
#### watching
  - `watch(globs, [options], [tasks])` api 제공, 
  - glob에 해당하는 파일 변경시 task 실행
  - 기본 딜레이와 큐잉이 적용되어있음.
  - 태스크가 비동기 완료하지 않으면 재실행되지 않는다.
  - `options.events`에 특정 이벤트만 등록할 수 있음.
    - `all` 이벤트는 `ready, error`제외 모든 이벤트를 나타냄
  - 처음 1회는 무조건 실행하려면 `options.ignoreInitial`을 `false`로 한다.
  - 다른 옵션들:
    - `options.queue: boolean`
    - `options.delay: number`
#### custom registries
`gulp.registry()`를 사용하여 공통 모듈, 추가 기능 확장 등을 할 수 있다.
- https://gulpjs.com/docs/en/advanced/creating-custom-registries
  - 
      


https://gulpjs.com/docs/en/getting-started/working-with-files

## inst
1. 설치
   1. `npm i -g gulp-cli`
2. 사용
   1. [예제 폴더](examples/index.md)에 정리

## dep
  - gulp
  - js

## ref
  - https://programmingsummaries.tistory.com/356
  - https://zetawiki.com/wiki/Gulp

## tags
  \#javascript, \#ecmascript, \#js, \#gulp



   