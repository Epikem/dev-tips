# node-js-babel-use-react-preset

바벨 노드 자바스크립트 리액트 프리셋 사용하기

----


- [desc](#desc)
- [inst](#inst)
    - [1. 다음 명령으로 설치](#1-다음-명령으로-설치)
    - [2.1 그리고 바벨 설정을 한다.](#21-그리고-바벨-설정을-한다)
    - [2.2 또한 cli로도 사용 가능](#22-또한-cli로도-사용-가능)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc
- 이 설정을 통해 .js파일에서 `<App>`과 같은 리액트 문법을 사용할 수 있게 된다.

## inst
#### 1. 다음 명령으로 설치
>shell
`npm install --save-dev babel-cli babel-preset-react`

#### 2.1 그리고 바벨 설정을 한다.
>babel config at package.json or .babelrc
```js
{
    "presets": ["react"]
}
```
끗.

#### 2.2 또한 cli로도 사용 가능
>shell
`babel script.js --presets react`

## dep
  - webpack:^3
  - babel-core:^6

## ref
  - [babel preset react doc](https://babeljs.io/docs/plugins/preset-react/)

## tags
  #babel, #nodejs, #javascript, #ecmascript, #js, #react



----

 
