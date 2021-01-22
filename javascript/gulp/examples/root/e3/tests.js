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

const { EventEmitter } = require('events');

function eventEmitterTask() {
  const emitter = new EventEmitter();
  // Emit has to happen async otherwise gulp isn't listening yet
  setTimeout(() => emitter.emit('finish'), 250);
  return emitter;
}

exports.event = eventEmitterTask;


function eventEmitterTask() {
  const emitter = new EventEmitter();
  // Emit has to happen async otherwise gulp isn't listening yet
  setTimeout(() => emitter.emit('not-finish'), 250);
  setTimeout(() => emitter.emit('finish'), 50000);
  return emitter;
}

exports.event2 = eventEmitterTask;

const { exec } = require('child_process');

function childProcessTask() {
  return exec('date');
}

exports.child = childProcessTask;


function childProcessTaskHang() {
  return exec('top');
}

exports.child2 = childProcessTaskHang;

const { Observable } = require('rxjs');

function observableTask() {
  return Observable.of(1, 2, 3);
}

exports.observable = observableTask;


function callbackTask(cb) {
  // `cb()` should be called by some async work
  cb();
}

exports.callback = callbackTask;

function callbackError(cb) {
  // `cb()` should be called by some async work
  cb(new Error('kaboom'));
}

exports.callbackError = callbackError;

const fs = require('fs');

function passingCallback(cb) {
  fs.access('gulpfile.js', cb);
}

exports.fs = passingCallback;

async function asyncAwaitTask() {
  const { version } = JSON.parse(fs.readFileSync('package.json', 'utf8'));
  console.log(version);
  await Promise.resolve('some result');
}

exports.asyncAwaitTask = asyncAwaitTask;

const babel = require('gulp-babel');
const uglify = require('gulp-uglify');
const rename = require('gulp-rename');

exports.doubleOutput = function() {
  return src('src/*.js')
    .pipe(babel({ presets: ['@babel/preset-env']}))
    .pipe(src('vendor/*.js'))
    .pipe(dest('output/'))
    .pipe(uglify())
    .pipe(rename({ extname: '.min.js' }))
    .pipe(dest('output/'));
}

const uglifyjs = require('uglify-js');
const through2 = require('through2');

exports.inline = function() {
  return src('src/*.js')
    // Instead of using gulp-uglify, you can create an inline plugin
    .pipe(babel({ presets: ['@babel/preset-env']}))
    .pipe(through2.obj(function(file, _, cb) {
      if (file.isBuffer()) {
        const code = uglifyjs.minify(file.contents.toString())
        file.contents = Buffer.from(code.code)
      }
      cb(null, file);
    }))
    .pipe(dest('output/'));
}