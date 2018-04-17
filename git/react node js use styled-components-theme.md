react node js use styled-components-theme
=====

----

[TOC]

## title
- 리액트 스타일드-컴포넌트-테마 패키지 설치하기 및 사용법

## desc
- 자바스크립트 리액트에서 스타일드 컴포넌트 테마 플러그인을 설치하여 색 및 테마를 관리한다.
  ? webpack이나 babel에서 추가 설정이 필요한가?

## inst
### 1. install by running below commands
> terminal
`yarn add styled-components-theme`

### 2.1 usage in file :

  see [>examples>react node js use styled-components-theme](../examples/react%20node%20js%20use%20styled-components-theme/index.js)

### 2.2 usage (scraped from [ref 1](##ref)):

##### 1. define theme colors


> :file_folder: color.js
```js
export default const colors = {
main:  '#393276',
dark:  '#0D083B',
light: '#837EB1'
}
```


##### 2. apply theme to app with `ThemeProvider`
>file: App.js
```jsx
import { ThemeProvider } from 'styled-components';
import colors from './colors' // from Step #1

const App = props =>
<ThemeProvider theme={colors}>
{props.children}
</ThemeProvider>
```

##### 3. create an importable theme object using styled-components-theme
>file: theme.js

```js
import createTheme from 'styled-components-theme';
import colors from './colors' // from Step #1

const theme = createTheme(...Object.keys(colors))
export default theme
```

##### 4. use the theme colors in your components
>file: App.js
```jsx
import styled from 'styled-components'
import theme from './theme' // from Step #3

const Header = styled.div`
background: ${theme.dark};
color: ${theme.light};
`

const Button = styled.button`
background-image: linear-gradient(${theme.light}, ${theme.light.darken(0.3)});
color: ${theme.dark};
padding: 10px;
```

Available manipulation functions

This library uses the color manipulation provided by the color library.

```js
theme.color.negate()         // rgb(0, 100, 255) -> rgb(255, 155, 0)

theme.color.lighten(0.5)     // hsl(100, 50%, 50%) -> hsl(100, 50%, 75%)
theme.color.darken(0.5)      // hsl(100, 50%, 50%) -> hsl(100, 50%, 25%)

theme.color.saturate(0.5)    // hsl(100, 50%, 50%) -> hsl(100, 75%, 50%)
theme.color.desaturate(0.5)  // hsl(100, 50%, 50%) -> hsl(100, 25%, 50%)
theme.color.greyscale()      // #5CBF54 -> #969696

theme.color.whiten(0.5)      // hwb(100, 50%, 50%) -> hwb(100, 75%, 50%)
theme.color.blacken(0.5)     // hwb(100, 50%, 50%) -> hwb(100, 50%, 75%)

theme.color.fade(0.5)        // rgba(10, 10, 10, 0.8) -> rgba(10, 10, 10, 0.4)
theme.color.opaquer(0.5)     // rgba(10, 10, 10, 0.8) -> rgba(10, 10, 10, 1.0)

theme.color.rotate(180)      // hsl(60, 20%, 20%) -> hsl(240, 20%, 20%)
theme.color.rotate(-90)      // hsl(60, 20%, 20%) -> hsl(330, 20%, 20%)

theme.color.mix(theme.otherColor, 0.2) // rgb(0, 0, 255) * 0.8 + rgb(0, 255, 0) * 0.2 -> rgb(0, 51, 204)
```

## dep
  - nodejs
  - react

## ref
  1. [github nodejs styled-components-theme package](https://github.com/erikras/styled-components-theme)

## tags
  #nodejs, #javascript, #ecmascript, #js, #react, #styled-components,  #styled-components-theme

