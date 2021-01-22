// from nodejs doc
// NewListener
const EventEmitter = require('events');

class MyEmitter extends EventEmitter {}

/**
 * @type {EventEmitter}
 */
const myEmitter = new MyEmitter();
// Only do this once so we don't loop forever

let i=0
function printRawListeners(emitter, pos){
  i+=1
  console.info(i, emitter.rawListeners('event'), pos)
}

printRawListeners(myEmitter, 'a')

myEmitter.once('newListener', (event, listener) => {
  printRawListeners(myEmitter, 'c')
  
  if (event === 'event') {
    printRawListeners(myEmitter, 'd')
    // Insert a new listener in front
    myEmitter.on('event', () => {
      console.log('B');
    });
    printRawListeners(myEmitter, 'e')
  }
});
printRawListeners(myEmitter, 'b')
myEmitter.on('event', () => {
  console.log('A');
});
printRawListeners(myEmitter, 'f')
myEmitter.emit('event');
printRawListeners(myEmitter, 'g')
// Prints:
//   B
//   A
