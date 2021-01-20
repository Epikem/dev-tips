require('manakin').global
const http = require('http')

console.log(process._getActiveHandles())
console.log(process._getActiveRequests())

const request = http.get('http://www.google.com')
console.log(process._getActiveRequests(), process._getActiveRequests().length)

const request2 = http.get('http://www.google.com')

setTimeout(() => {
  console.info('done')
}, 1000);

console.log(process._getActiveRequests(), process._getActiveRequests().length)

request.on('finish', () => {
  console.log('finish1')
  console.log(process._getActiveRequests(), process._getActiveRequests().length)
})

request2.on('finish', () => {
  console.log('finish2')
  console.log(process._getActiveRequests(), process._getActiveRequests().length)
})