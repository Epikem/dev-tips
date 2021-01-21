gulp-usage
=====

----


- [gulp-usage](#gulp-usage)
  - [title](#title)
  - [desc](#desc)
    - [소개](#소개)
    - [api](#api)
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
- 태스크 선언
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
- series, parallel
  - 순차/병렬 태스크 실행

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



   