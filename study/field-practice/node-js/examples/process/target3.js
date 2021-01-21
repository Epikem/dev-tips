const process = require('process')
console.info('target 3 starting')

const readline = require('readline');

readline.emitKeypressEvents(process.stdin);
if (process.stdin.isTTY) {
  process.stdin.setRawMode(true);
} else {
  console.error('is not TTY')
  // process.exit(1)
}

process.stdin.on('keypress', (str, key) => {
  console.info('yo')
  console.info(str, key)

  if(key.ctrl && key.name === 'c'){
    process.exit(0)
  }

})