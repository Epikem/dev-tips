gulp-usage
=====

----


- [title](#title)
- [desc](#desc)
  - [소개](#소개)
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



   