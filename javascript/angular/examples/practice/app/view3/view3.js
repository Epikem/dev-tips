'use strict';

angular.module('myApp.view3', ['ngRoute'])

.config(['$routeProvider', function($routeProvider) {
  $routeProvider.when('/view3', {
    templateUrl: 'view3/view3.html',
    controller: 'View3Ctrl'
  });
}])

.controller('View3Ctrl', [function() {

}])

.controller('FilterController', ['$scope', function($scope) {
  $scope.checked = true
}])

.filter('checkmark', function(){
  return function(input, colored){
    if(colored){   // colored is truthy
      console.log('colored')
      return input ? '\u2705' : '\u274c'
    }
    return input ? '\u2713' : '\u2718'
  }
})

.config(['$httpProvider', function($httpProvider) {
  $httpProvider.defaults.xsrfTrustedOrigins= ['https://ptsv2.com']
  $httpProvider.defaults.xsrfWhitelistedOrigins = ['https://ptsv2.com']
}])

.controller('HTTPController', ['$scope', '$http', function($scope, $http) {
  $scope.withCredentials = false
  $scope.useCache = false
  $scope.get = ()=>{
    $http({
      method: 'GET',
      url: 'https://httpbin.org/get',
      withCredentials: $scope.withCredentials,
      cache: $scope.useCache,
    }).then(res=>{
      console.log(res)
    }).catch(err=>{
      console.error(err)
    })
  }
  $scope.post = () => {
    $http({
      method: 'POST',
      data: {asd:'fds'},
      // headers: {
      //   'Access-Control-Allow-Origin': 'https://ptsv2.com, http://localhost:8000'
      // },
      // headers: {
      //   "Access-Control-Allow-Methods": "GET, POST",
      //   "Access-Control-Allow-Origin": "*",
      //   "Access-Control-Allow-Credentials" : true // Required for cookies, authorization headers with HTTPS
      // },
      url: 'https://httpbin.org/post',
      withCredentials: $scope.withCredentials,
      cache: $scope.useCache
    }).then(res=>{
      console.log(res)
    }).catch(err=>{
      console.error(err)
    })
  }
}])

.controller('ScopeInheritanceExampleController', ['$rootScope', '$scope', function($rootScope, $scope) {
  $scope.parentScopeValue = 'parent'
  $rootScope.rootScopeValue = 'root'
  $scope.$root.rootByRef = 'rootByRef'
}])

.controller('ScopeInheritanceExampleNestedController', function($scope) {
  $scope.nestedScopeValue = 'nested'
})

.controller('ScopeEventExampleController', function($scope) {
  
})