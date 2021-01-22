// from nodejs doc, modified

const EventEmitter = require('events');

class MyEmitter extends EventEmitter {}

const myEmitter = new MyEmitter();
myEmitter.on('event', (a, b) => {
  console.log('this happens, sync1')
  setImmediate(() => {
    console.log('this happens asynchronously');
  });
  process.nextTick((val)=>{
    console.log('this is also async', val)
  })
  console.log('this happens, sync2')
});
myEmitter.emit('event', 'a', 'b');
