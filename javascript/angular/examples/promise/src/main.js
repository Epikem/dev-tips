
function fetchData(cb){
  return new Promise(function(resolve, reject){
    // $.get('/data', function(response){
    //   if(response){
    //     resolve(response)
    //   }
    //   reject('asd')
    // })
    setTimeout(()=>{
      resolve('asd');
      reject('fdfs')
    }, 1000)
  })  
}

// const get1 = new Promise((resolve, reject)=>{
//   setTimeout()
// })

fetchData().then(function(data){
  console.log(data)
}).catch(function(error){
  console.error(error)
})