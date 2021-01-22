require('manakin').global

const { fork } = require('child_process')
const { argv } = require('process')
const readline = require('readline')

// const child = exec(`node ${argv[2]} ${argv.slice(3)}`)
const child = fork(`./src/${argv[2]}`, argv.slice(3))

child.on('close', (code, signal)=>{
  console.info('child close')
  console.log(code, signal)
  process.exit(0)
})

child.on('exit', (code, signal)=>{
  console.info('child exit')
  console.log(code, signal)
})

child.on('message', (message, handle)=>{
  console.info('child msg')
  console.log(message)
})
readline.emitKeypressEvents(process.stdin);
if (process.stdin.isTTY) {
  process.stdin.setRawMode(true);
} else {
  console.error('is not TTY')
  // process.exit(1)
}

let buffer = []
process.stdin.on('keypress', (str, key) => {
  // console.info('yo2')
  // console.info(str, key)
  if(key.name==='return'){
    const command = buffer.join('')
    console.log(command)
    buffer = []
    child.send(command)
    if(command==='kill'){
      child.kill('SIGTERM')
    }
  } else {
    buffer.push(key.sequence)
  }
  
  if(key.ctrl && key.name === 'c'){
    process.exit(0)
  }

})