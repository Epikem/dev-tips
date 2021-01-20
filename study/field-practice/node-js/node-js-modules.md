# node-js-modules

노드 모듈 관련 공부

----


- [node-js-modules](#node-js-modules)
  - [desc](#desc)
  - [module 개요](#module-개요)
    - [module-wrapper](#module-wrapper)
    - [폴더로서의 모듈:](#폴더로서의-모듈)
    - [node_modules:](#node_modules)
    - [NODE_PATH](#node_path)
  - [Path](#path)
    - [path.basename(path[, ext])](#pathbasenamepath-ext)
    - [path.delimiter](#pathdelimiter)
  - [dep](#dep)
  - [ref](#ref)
  - [tags](#tags)

## desc

node-js module 관련 공부

## module 개요

node js에서 개별 파일이 각각의 모듈로 처리된다.
모듈의 지역 변수는 private인데, 모듈이 런타임에 의해 [함수로 감싸지기 때문](https://nodejs.org/docs/latest-v10.x/api/modules.html#modules_the_module_wrapper)이다.

### module-wrapper

node js는 모듈을 다음과 같이 함수로 감싼다

```js
(function(exports, require, module, __filename, __dirname) {
// Module code actually lives in here
});
```

모듈을 함수로 감싸서, 노드 모듈은 다음과 같은 기능을 얻는다:
- 최상위 레벨 변수들(var,let,const)의 범위가 전역이 아닌 해당 모듈로 제한된다.
- 전역변수같은 기능들을 모듈이 제공받을 수 있다
  - exports
    - `module.exports`의 단축명. https://nodejs.org/docs/latest-v10.x/api/modules.html#modules_exports_shortcut
    - 
  - require
  - module
    - __filename
    - symlink를 푼 실제 파일 경로+이름
    - __dirname
    - `path.dirname(__filename)`과 동일
    - 등: `[module.filename, __filename, module.id, module.loaded, module.paths, module.require, module.children, module.exports]`

###  폴더로서의 모듈:
  - `package.json`의 `main`항목에 메인 진입점을 제공하면, 다른 모듈에서 로드 가능
  - `main`항목을 찾지 못하면, `index.js`나 `index.node`를 찾는다.
  
### node_modules:
  - 로드하려는 모듈이 코어 모듈이나, 경로 지정된 모듈이 아니면, 현재 폴더로부터 경로를 올라가면서 `node_modules`폴더에 해당 모듈이 있는지 찾는다.

### NODE_PATH
  - 다른 곳에서 모듈을 찾지 못하면 해당 경로를 찾는다.

## Path

- 현재 운영체제에 따라 동작이 다르다
On POSIX:
```js
path.basename('C:\\temp\\myfile.html');
// Returns: 'C:\\temp\\myfile.html'
```
On Windows:
```js
path.basename('C:\\temp\\myfile.html');
// Returns: 'myfile.html'
```

- 특정 운영체제에 따른 동작을 원하면 해당 하위 모듈 사용 (`path.win32` 또는 `path.posix`)

### path.basename(path[, ext])

경로의 마지막 부분 반환

### path.delimiter

플랫폼 종속 구분자 반환
- 윈도: ;
- posix: :






## dep

## ref
  - [node modules doc](https://nodejs.org/docs/latest-v10.x/api/modules.html)

## tags
  \#nodejs, \#javascript, \#ecmascript, \#js, \#node-module



----

 
