const process = require('process')
console.info('target 4 starting')

function callback1(msg){
  console.log('listener 1 :', msg)
}
process.addListener('message', callback1)

function callback2(msg){
  console.log('listener 2 :', msg)
  if(msg==='con 3'){
    process.addListener('message', callback3)
  }
}
process.addListener('message', callback2)

function callback3(msg){
  console.log('listener 3 :', msg)
  if(msg==='dis 3'){
    process.removeListener('message', callback3)
  }
}


