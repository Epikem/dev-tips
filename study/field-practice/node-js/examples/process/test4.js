require('manakin').global
// https://mylko72.gitbooks.io/node-js/content/chapter9/chapter9_1.html

const process = require('process')
const { exec } = require('child_process')
const { argv } = require('process')

console.warn('process.env')
console.log(process.env)
console.warn('process.argv')
console.log(process.argv)
console.log(process.argv[2])

const resultEvent = exec('ls', (error, stdout, stderr)=> {
  if (error) {
    console.error(`exec error: ${error}`);
    return;
  }
  console.log(`stdout: ${stdout}`);
  console.log(`stderr: ${stderr}`);
})