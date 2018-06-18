# webpack-node-js-add-folder-alias-for-import
자바스크립트 웹팩 폴더 별칭 설정하기

----

- [desc](#desc)
- [inst](#inst)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc
- 웹팩에서 절대경로로 모듈을 임포트 해야할때 폴더 별칭이 필요하다.

## inst

- webpack config에서 (ex: `webpack.config.dev.js`)
```js
- webpack config
Templates: path.resolve(__dirname, 'src/templates/')
```

이런식으로 해 두면 나중에 리액트 코드에서
```jsx
- react
import {Something} from 'Templates';
```




이렇게 하여 `'src/templates'` 의 `SomeThing`을 불러올 수 있다. 그러나 특정 설정이 되어있으면 다음과 같은 에러를 내며 빌드가 실패한다.
> terminal
```
./src/App.js
Module not found: You attempted to import E:\\..\\ui\\config\\src\\views which falls outside of the project src/ directory. Relative imports outside of src/ are not supported. You can either move it inside src
/, or add a symlink to it from project's node_modules/.
```
이때는 그냥 다음처럼 한다.
> webpack config
```js
Templates: path.resolve('src/templates')
```
그러면 설정이 다음처럼 된다:
> file: webpack.config
```js
...
  resolve:{
    alias:{
      Templates: path.resolve('src/templates')
    }
  }
```

이제부터는
```jsx
import {Something} from 'Templates';
```
처럼 절대경로로 읽어올 수 있게 된다.

https://webpack.js.org/configuration/resolve/ 에 어떤 alias 설정이 실제 어떻게 import되는지 알려주는 참고 테이블이 있다.

## dep
  - webpack:`^3.0.0`

## ref

## tags
  #webpack, #ecmascript, #js, #node
