'use strict';

angular.module('myApp.view2', ['ngRoute'])

.config(['$routeProvider', function($routeProvider) {
  $routeProvider.when('/view2', {
    templateUrl: 'view2/view2.html',
    controller: 'View2Ctrl'
  });
}])


.controller('View2Ctrl', [function() {

}])

.controller('SwitchController', ['$scope', function($scope) {
  $scope.items = ['settings', 'home', 'options', 'other'];
  $scope.selection = $scope.items[0];
}])

.controller('repeatController', function($scope) {
  var friends = [
    {name:'John', age:25},
    {name:'Mary', age:40},
    {name:'Peter', age:85}
  ];

  $scope.removeFirst = function() {
    $scope.friends.shift();
  };

  $scope.updateAge = function() {
    $scope.friends.forEach(function(el) {
      el.age = el.age + 5;
    });
  };

  $scope.copy = function() {
    $scope.friends = angular.copy($scope.friends);
  };

  $scope.reset = function() {
    $scope.friends = angular.copy(friends);
  };

  $scope.reset();
})

.controller('filterController', function($scope){
  $scope.text = 'test text';
})

// .animation('.bold', [function() {
//   return {
//     addClass: function(element, className, doneFn) {
//       console.log(element, className)
//       doneFn();
//       // do some cool animation and call the doneFn
//     },
//     removeClass: function(element, className, doneFn) {
//       // do some cool animation and call the doneFn
//     },
//     setClass: function(element, addedClass, removedClass, doneFn) {
//       // do some cool animation and call the doneFn
//     }
//   }
// }]);