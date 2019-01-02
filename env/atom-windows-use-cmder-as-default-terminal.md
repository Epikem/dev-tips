# atom-windows-use-cmder-as-default-terminal

윈도우 아톰에서 cmder를 기본 터미널로 사용하기.

--------------------------


- [desc](#desc)
- [inst](#inst)
- [dep](#dep)
- [tags](#tags)

## desc
- 윈도우, 아톰, cmder은 설치되있다고 가정.
- atom에 cmder을 연결시켜 편하게 다중 터미널을 사용한다.

## inst
- instruction
  1. atom 패키지 open-terminal-here 설치
  2. atom 패키지 tree-view 설치
  3. cmder 설정 :
      1. cmder 설정에서 Appearance - Single instance mode 체크 (안하면 각각 다른 창 사용)
      2. cmder 설정에서 Tasks에서 원하는 태스크 만들기
      > ex) `{Shell::PowerShell (Admin)}` 사용,
      `powershell.exe -cur_console:a -cur_console:d:"E:\Epikem\dev\Repos " -NoExit  -Command "Invoke-Expression '. ''%ConEmuDir%\..\profile.ps1'''"`
  4. open-terminal-here에서 command를 설정 :
  > ex) `cmder.exe /task "Shells::PowerShell (Admin)"`

  task 이름을 " "로 감싼 것에 유의.

## dep
  - windows
  - atom for windows
  - cmder
  <!-- - atom package : open-terminal-here
  - atom package : tree-view -->

<!-- ## ref -->
  <!-- - [stackoverflow](https://stackoverflow.com/questions/)
  - [github](https://github.com/Epikem) -->

## tags
  #windows, #atom, #cmder, #scoop



--------------------------

 