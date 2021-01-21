const process = require('process')
console.info('target 2 starting')

const readline = require('readline');

console.log(process.argv)

process.on('message', (message)=>{
  console.log('got', message)
  if(message ==='exit'){
    process.exit(0)
  }
})

async function init() {
  console.log(1);
  await sleep(1000);
  for (let i = 0; i < 10; i++) {
    await sleep(1000);
    console.log(i)
    
  }
}

function sleep(ms) {
  return new Promise((resolve) => {
    setTimeout(resolve, ms);
  });
}   

init()

// readline.emitKeypressEvents(process.stdin);
// if (process.stdin.isTTY) {
//   process.stdin.setRawMode(true);
// } else {
//   console.error('is not TTY')
//   // process.exit(1)
// }


// process.stdin.on('keypress', (str, key) => {
//   console.info('yo')
//   console.info(str, key)

//   if(key.ctrl && key.name === 'c'){
//     process.exit(0)
//   }

// })