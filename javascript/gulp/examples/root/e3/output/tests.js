const { src, dest } = require('gulp');

function streamTask() {
  return src('*.js')
    .pipe(dest('output'));
}

exports.stream = streamTask;

function promiseTask() {
  return Promise.resolve('the value is ignored');
}


exports.promise = promiseTask;
