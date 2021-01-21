# node-js-path

노드 Path 관련 공부

----


- [node-js-path](#node-js-path)
  - [desc](#desc)
  - [Path](#path)
    - [path.basename(path[, ext])](#pathbasenamepath-ext)
    - [path.delimiter](#pathdelimiter)
    - [path.dirname(path)](#pathdirnamepath)
    - [path.extname(path)](#pathextnamepath)
    - [path.format(pathObject)](#pathformatpathobject)
    - [path.isAbsolute(path)](#pathisabsolutepath)
    - [path.join([...paths])](#pathjoinpaths)
    - [path.normalize(path)](#pathnormalizepath)
    - [path.parse(path)](#pathparsepath)
    - [path.posix](#pathposix)
    - [path.relative(from, to)](#pathrelativefrom-to)
    - [path.resolve([...paths])](#pathresolvepaths)
    - [path.sep](#pathsep)
    - [path.win32](#pathwin32)
  - [dep](#dep)
  - [ref](#ref)
  - [tags](#tags)

## desc

node-js path 관련 공부

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

플랫폼 종속 delimiter
- 윈도: ;
- posix: :

### path.dirname(path)

파일이름 제외한 경로 이름 반환

```js
path.dirname('/foo/bar/baz/asdf/quux');
// Returns: '/foo/bar/baz/asdf'
```

### path.extname(path)

### path.format(pathObject)

### path.isAbsolute(path)

### path.join([...paths])

### path.normalize(path)

### path.parse(path)

### path.posix

### path.relative(from, to)

### path.resolve([...paths])

paths 배열로부터 계산된 절대 경로 반환. 절대 경로가 계산되지 않으면 현재 경로를 기준으로 계산.

### path.sep

플랫폼 종속 구분자

### path.win32


## dep

## ref
  - [node path doc](https://nodejs.org/docs/latest-v10.x/api/path.html)

## tags
  \#nodejs, \#javascript, \#ecmascript, \#js, \#path



----

 
