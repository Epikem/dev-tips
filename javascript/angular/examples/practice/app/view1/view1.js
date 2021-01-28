'use strict';



angular.module('myApp.view1', ['ngRoute'])


.config(['$routeProvider', function($routeProvider) {
  $routeProvider.when('/view1', {
    templateUrl: 'view1/view1.html',
    controller: 'View1Ctrl'
  });

}])

.config(['$httpProvider', function($httpProvider){
  console.log($httpProvider);
  // $httpProvider.xsrfWhitelistedOrigins.push('http://localhost:8080');
  // // $httpProvider.xsrfTrustedOrigins.push('http://localhost:8080');
  // $httpProvider.defaults.headers.common['Access-Control-Allow-Origin']= '*';
  console.log($httpProvider);
  return $httpProvider;
}])

.controller('View1Ctrl', ['$scope', '$http', '$templateCache', function($scope, $http, $templateCache) {
    $scope.method = 'GET';
    $scope.url = 'http://localhost:8080/api/pagination?page=1&perPage=10';
    $scope.data = [];

    $scope.fetch = function() {
      $scope.code = null;
      $scope.response = null;

      $http({method: $scope.method, url: $scope.url, cache: $templateCache}).
        then(function(response) {
          $scope.status = response.status;
          $scope.data = response.data;
          console.log($scope.data);
        }, function(response) {
          $scope.data = response.data || 'Request failed';
          $scope.status = response.status;
      })
    };
    

}]);