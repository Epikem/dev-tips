# windows-nodejs-install-node-canvas

윈도우 노드에서 node-canvas 설치하기

--------------------------


- [desc](#desc)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc
요약: (ref 1)을 참조하면 된다.

prebuilt 없이 node-canvas를 설치하려면 전역으로 설치된 node-gyp가 필요하지만(나를 삽질시킨), 기본적으로 prebuilt된 채로 받기 때문에 node-gyp 제외하고 그 외의 라이브러리들이 필요하다.
아래는 확실히 호환된다고 알려진 설정.

- node-canvas 1.3.4
- GTK+ 2.22.1
- libjpeg-turbo64 1.4.2

근데 경로 문제로 또 골아파지기 싫었기 때문에 GTK와 libjepeg-turbo는 그냥 C:\에 설치했다.

GTK 없이 설치하면 cairo 머시기가 없다고 뜨고, libjpeg없이 설치하려 하면 jpeglib가 없다고 나온다.

`c:\users\administrator\dropbox\dev\project\keter\node_modules\canvas\src\image.h(5): fatal error C1083: Cannot open include file: 'cairo.h': No such file or directory (compiling source file ..\src\Image.cc) [C:\Users\Administrator\Dropbox\dev\project\keter\node_modules\canvas\build\canvas.vcxproj]`

`c:\users\administrator\dropbox\dev\project\keter\node_modules\canvas\src\closure.h(6): fatal error C1083: Cannot open include file: 'jpeglib.h': No such file or directory (compiling source file ..\src\backend\SvgBackend.cc) [C:\Users\Administrator\Dropbox\dev\project\keter\node_modules\canvas\build\canvas.vcxproj]`

## dep

## ref
  - [issue](https://github.com/Automattic/node-canvas/issues/619)

## tags
  #windows, #nodejs, #node-canvas, #node-package



--------------------------


 