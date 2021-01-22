# node-js-event-study

노드 event 공부

----

- [목적](#목적)
- [상세](#상세)
- [newListener](#newlistener)
- [addListener](#addlistener)
- [removeListener](#removelistener)
- [emit](#emit)
- [on](#on)
- [off](#off)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## 목적
- 비동기 처리를 위해 사용
  - io, 요청, 스트림 등

## 상세
- 이벤트를 내보내는 모든 object는 `EventEmitter`클래스이다.
- Event가 발생되면, 해당 이벤트를 듣는 모든 리스너들이 *동기적으로* 실행된다.
- 리스너 함수에서 `this`는 `EventEmitter`를 가리킨다.
  - es6의 Arrow 함수를 사용할 경우는 제외.
- *순서 보장*: 이벤트 리스너는 그들이 등록된 순서대로 실행된다
- 

## newListener
- 새 내부 리스너 배열에 리스너를 추가하기 *전에* 해당 이벤트를 발생한다.
- 따라서 같은 이름의 이벤트에 등록되는 `newListener` 콜백에서 추가되는 리스너가 항상 다른 리스너에 비해 내부 배열에서 먼저 등록되고, 먼저 실행된다. (example/node-js-event-study/src/e5.js)

## addListener
- `emitter.on`의 별칭
- `emitter.addListener(eventName, listener) == emitter.on(eventName, listener)`

## removeListener
- 리스너를 제거 *후* 실행되는 이벤트

## emit
`emitter.emit(eventName[, ...args])`
event를 실행? x

해당 이벤트에 등록된 리스너들을 *동기적으로, 등록 순서대로* 실행
리스너가 있으면 true, 없으면 false 반환

## on
event가 실행될 때마다 실행되는 함수를 등록

## off
- `emitter.removeListener()`의 별칭

## dep
  - nodejs

## ref
  - [node js even doc](https://nodejs.org/docs/latest-v10.x/api/events.html)
  - https://stackoverflow.com/questions/15349733/setimmediate-vs-nexttick

## tags
  \#nodejs, \#javascript, \#ecmascript, \#js, \#node-event, \#study



----

 
