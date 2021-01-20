require('manakin').global
// https://mylko72.gitbooks.io/node-js/content/chapter9/chapter9_1.html

const process = require('process')

console.info(process.pid)

const { spawn } = require('child_process');
const ls = spawn('ls', ['-lh', '/usr']);

ls.stdout.on('data', (data) => {
  console.log(`stdout: ${data}`);
});

ls.stderr.on('data', (data) => {
  console.log(`stderr: ${data}`);
});

ls.on('close', (code) => {
  console.log(`child process exited with code ${code}`);
});

const readline = require('readline');

readline.emitKeypressEvents(process.stdin);
process.stdin.setRawMode(true);

const maps = [
  ['0','0','x','x','x'],
  ['x','0','x','0','x'],
  ['x','0','x','0','x'],
  ['x','0','x','0','x'],
  ['x','0','0','0','0'],
]
const state = {
  pos: {
    r:0,
    c:0
  }
}

// l d r u
const dc=[-1, -0, +1, +0, 0]
const dr=[+0, +1, -0, -1, 0]

function move(dir, r,c, mr, mc) {
  let [nr,nc] = [r+dr[dir], c+dc[dir]]
  if(nr<0){
    nr = 0
  }
  if(nr>=mr){
    nr=mr-1
  }
  if(nc<0){
    nc=0
  }
  if(nc>=mc){
    nc=mc-1
  }
  if(maps[nr][nc] ==='x'){
    return {nr:r, nc:c}
  }
  return {nr,nc}
}

process.stdin.on('keypress', (str, key) => {
  console.log(str)
  // console.log(key)
  console.log()
  console.log()
  console.log()
  console.log()
  console.log()
  console.log()
  console.log()
  console.log()
  console.log()
  let dir = 4
  if(key.name==='left'){
    dir=0
  } else if(key.name==='down'){
    dir=1
  }else if(key.name==='right'){
    dir=2
  } else if(key.name==='up'){
    dir=3
  }
  const {r, c} =state.pos
  const {nr,nc} = move(dir, r, c,maps.length, maps[0].length)
  state.pos = {r:nr, c:nc}
  if(key.ctrl && key.name === 'c'){
    process.exit(0)
  }


  for (let r = 0; r < maps.length; r++) {
    const row = maps[r];
    const out = []
    for (let c = 0; c < maps[r].length; c++) {
      const cell = maps[r][c];
      if(r===state.pos.r && c===state.pos.c){
        out.push('O')
      } else {
        out.push(cell)
      }
    }
    console.log(out.join(''))
  }
  console.log(state.pos)
})
