angular
  .module('core')
  .filter('checkmark', function(){
    return function(input){
      return input ? '\u2713' : '\u2718'
    }
  })




// angular.module('myApp.version.interpolate-filter', [])

// .filter('interpolate', ['version', function(version) {
//   return function(text) {
//     return String(text).replace(/\%VERSION\%/mg, version);
//   };
// }]);
