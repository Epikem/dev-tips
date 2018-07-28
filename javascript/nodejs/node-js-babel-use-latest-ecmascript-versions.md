node-js-babel-use-latest-ecmascript-versions
=====

----


- [inst](#inst)
    - [1. 다음 명령으로 설치](#1-다음-명령으로-설치)
    - [2. 그리고 바벨 설정을 한다.](#2-그리고-바벨-설정을-한다)
    - [2.2. 브라우저 호환 설정](#22-브라우저-호환-설정)
    - [2.3 서버용으로 설정](#23-서버용으로-설정)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## inst
####  1. 다음 명령으로 설치
>shell
`npm install babel-preset-env --save-dev`

####  2. 그리고 바벨 설정을 한다.
>babel config at package.json or .babelrc
```js
{
  "presets": ["env"]
}
```

이렇게 하여 기본 최신 버전을 사용
or

####  2.2. 브라우저 호환 설정

>babel config at package.json or .babelrc
```js
{
  "presets": [
    ["env", {
      "targets": {
        "browsers": ["last 2 versions", "safari >= 7"]
      }
    }]
  ]
}
```

이렇게 하여 특정 브라우저 호환을 설정할 수 있다.
or
#### 2.3 서버용으로 설정
```js
{
  "presets": [
    ["env", {
      "targets": {
        "node": "current"
      }
    }]
  ]
}
```

브라우저가 아닌 서버용으로 하려면 타겟을 노드로 하면 된다. 위처럼 node:current 쓰면 현재 바벨을 돌리는 노드에 필요한 만큼의 polyfill과 transform만 포함된다고 한다.

## dep
  - babel
  - node

## ref
  - [stackoverflow](https://stackoverflow.com/questions/)
  - [github](https://github.com/Epikem)

## tags
  #babel, #node, #javascript, #js, #ecmascript



----

 
