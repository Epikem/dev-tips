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
    - [process.channel](#processchannel)
    - [process.chdir(directory)](#processchdirdirectory)
    - [process.connected](#processconnected)
    - [process.disconnect()](#processdisconnect)
    - [process.cwd()](#processcwd)
    - [process.env](#processenv)
    - [process.exit([code])](#processexitcode)
    - [process.hrtime([time])](#processhrtimetime)
    - [process.kill(pid[, signal])](#processkillpid-signal)
    - [활용 방안](#활용-방안)
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

표준 posix signal events : https://man7.org/linux/man-pages/man7/signal.7.html
윈도우에서는 동작 안함.

### process.abort()
중지

### process.arch
os 정보

### process.argv

커맨드라인 인수, 첫번째 인자는 실행파일 경로

### process.channel

IPC 채널를 가리키거나, `undefined`.

### process.chdir(directory)

경로 이동, `Worker`에서 불가.

### process.connected

IPC 채널 연결 여부


### process.disconnect()
IPC 채널 연결 해제

### process.cwd()
현재 경로

### process.env

프로세스의 환경변수에 접근 가능

### process.exit([code])
종료

### process.hrtime([time])

상세 시간 

### process.kill(pid[, signal])
강제종료


### 활용 방안

- worker를 통한 작업 병렬처리
- 프로세스 모니터링
- 비동기 처리


https://stackoverflow.com/questions/17861362/node-js-child-process-difference-between-spawn-fork


## dep

## ref
  - [node process doc](https://nodejs.org/docs/latest-v10.x/api/process.html)

## tags
  \#nodejs, \#javascript, \#ecmascript, \#js, \#process



----

 
