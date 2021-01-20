# node-js-process

노드 process 관련 공부

----


- [node-js-process](#node-js-process)
  - [desc](#desc)
  - [process](#process)
    - [Signal Events](#signal-events)
    - [process.abort()](#processabort)
    - [process.arch](#processarch)
    - [process.argv](#processargv)
    - [process.chdir(directory)](#processchdirdirectory)
    - [process.connected](#processconnected)
    - [process.disconnect()](#processdisconnect)
    - [process.env](#processenv)
    - [process.exit([code])](#processexitcode)
  - [dep](#dep)
  - [ref](#ref)
  - [tags](#tags)

## desc

node-js process 관련 공부

## process

- process는 `EventEmitter`의 인스턴스임
- 다음과 같은 이벤트들 제공
  - Event: 'beforeExit'
  - Event: 'disconnect'
  - Event: 'exit'
  - Event: 'message'
  - Event: 'multipleResolves'
  - Event: 'rejectionHandled'
  - Event: 'uncaughtException'
  - Event: 'unhandledRejection'
  - Event: 'warning'

### Signal Events

### process.abort()

### process.arch

### process.argv

### process.chdir(directory)

### process.connected

### process.disconnect()

### process.env

### process.exit([code])




## dep

## ref
  - [node process doc](https://nodejs.org/docs/latest-v10.x/api/process.html)

## tags
  \#nodejs, \#javascript, \#ecmascript, \#js, \#process



----

 
