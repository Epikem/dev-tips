'use strict';

angular.module('myApp.view4', ['ngRoute'])

.config(['$routeProvider', function($routeProvider) {
  $routeProvider.when('/view4', {
    templateUrl: 'view4/view4.html',
    controller: 'View4Ctrl'
  });
}])

.controller('View4Ctrl', [function() {

}])

.factory('MyService1', function () {
  this.myval = this.myval+1 || 1
  console.log('MyService1 called', this.myval, 'times')
  return {
    getValue(val) {
      return val
    }
  }
})

.factory('UnusedService', function () {
  this.myval = this.myval+1 || 1
  console.log('UnusedService called', this.myval, 'times')
  return {
    getValue(val) {
      return val
    }
  }
})

.factory('NgIfService', ['MyService1', function(MyService1) {
  this.myval = this.myval+1 || 1
  console.log('NgIfService called', this.myval, 'times')
  return {
    run(val) {
      console.log(MyService1.getValue(val))
    }
  }
}])

.factory('NgShowService', ['MyService1', function(MyService1) {
  this.myval = this.myval+1 || 1
  console.log('NgShowService called', this.myval, 'times')
  return {
    run(val) {
      console.log(MyService1.getValue(val))
    }
  }
}])

.factory('CycleService1', ['CycleService2', function(CycleService2) {
  this.myval = this.myval+1 || 1
  console.log('CycleService1 called', this.myval, 'times')
  return {
    getValue(val) {
      return val
    },
    run(val) {
      console.log(CycleService2.getValue(val))
    }
  }
}])

.factory('CycleService2', ['CycleService1', function(CycleService1) {
  this.myval = this.myval+1 || 1
  console.log('CycleService2 called', this.myval, 'times')
  return {
    getValue(val) {
      return val
    },
    run(val) {
      console.log(CycleService1.getValue(val))
    }
  }
}])

.controller('ServiceExampleController', ['$scope', 'NgIfService', function($scope, NgIfService) {
  $scope.checked = true
  NgIfService.run('ng-if')
}])

.controller('ServiceExampleControllerNgShow', ['$scope', 'NgShowService', function($scope, NgShowService) {
  NgShowService.run('ng-show')
}])

.controller('CycleService1ExampleController', ['CycleService1', function(CycleService1) {
  CycleService1.run('no way')
}])
