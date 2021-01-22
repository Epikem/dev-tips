// from nodejs doc
// removeListener
const EventEmitter = require('events');

class MyEmitter extends EventEmitter {}

/**
 * @type {EventEmitter}
 */
const myEmitter = new MyEmitter();
let i = 0

let j=0
function printRawListeners(emitter, pos){
  j+=1
  console.info(emitter.rawListeners('event'), pos)
  emitter.rawListeners('event').forEach(listener => {
    console.log(listener.fname)
  });
}

printRawListeners(myEmitter, 'a')

const func = (a,b)=>{
  printRawListeners(myEmitter, 'e')
  i+=1
  console.log('called', i , 'times')
  console.log(a,b)
  myEmitter.off('event', func)
  printRawListeners(myEmitter, 'g')
}
func.fname = 'func1'

const removed = (eventName, handler) =>{
  printRawListeners(myEmitter, 'f')
  console.log('removed called', eventName, handler)
}

removed.fname = 'func2'

printRawListeners(myEmitter, 'b')
myEmitter.on('removeListener', removed)
printRawListeners(myEmitter, 'c')
myEmitter.addListener('event', func)
printRawListeners(myEmitter, 'd')
myEmitter.emit('event',2,3);
printRawListeners(myEmitter, 'h')
myEmitter.emit('event',2,3);
printRawListeners(myEmitter, 'i')
// Prints:
//   B
//   A
