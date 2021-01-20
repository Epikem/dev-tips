require('manakin').global
// https://mylko72.gitbooks.io/node-js/content/chapter4/chapter4_2.html
var events = require('events');
var emitter = new events.EventEmitter();
emitter.emit("simpleEvent");

function MyObj(){
  events.EventEmitter.call(this);
}
MyObj.prototype.__proto__ = events.EventEmitter.prototype;

var myObj = new MyObj();
myObj.emit("someEvent");

function myCallback(){
  console.info('callback called!')
}
var myObject = new MyObj();
myObject.on("someEvent", myCallback);

myObject.emit('someEvent')
