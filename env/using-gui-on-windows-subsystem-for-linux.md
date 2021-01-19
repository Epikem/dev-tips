# using-gui-on-windows-subsystem-for-linux

윈도우 wsl에서 gui 사용하기.

--------------------------

- [prereq](#prereq)
- [desc](#desc)
- [inst](#inst)
- [ref](#ref)
- [dep](#dep)
- [tags](#tags)

## prereq
- 윈도우, WSL (Windows Subsystem for Linux)

## desc
- 아래 블로그 포스트 참조. (ref 1)

## inst

wsl 1에서는 블로그 글대로 하니 잘 되었었는데, wsl 2로 재설치하고 다시 설치했는데 `can't open display 0`라면서 작동이 안 되었다. 찾아본 결과 (ref 2) wsl 2는 다른 ip를 가진 가상머신이므로 xlaunch로 xming 서버를 작동할 때 no access control 옵션을 켜주어야 한다. 그리고 호스트의 ip를 다음 명령으로 찾아서 설정해야 한다:
`export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0`


## ref
- https://www.tuwlab.com/ece/29485
- https://github.com/microsoft/WSL/issues/4106

## dep

## tags
  \#windows, \#windows-wsl, \#xming, \#linux, \#env



--------------------------


 