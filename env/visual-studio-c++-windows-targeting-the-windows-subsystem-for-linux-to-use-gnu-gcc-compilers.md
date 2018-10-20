# visual-studio-c++-windows-targeting-the-windows-subsystem-for-linux-to-use-gnu-gcc-compilers

윈도우 비주얼 스튜디오에서 WSL로 타게팅하여 gcc 컴파일러로 c++ 프로젝트 빌드하기.

--------------------------


- [prereq](#prereq)
- [desc](#desc)
- [inst](#inst)
- [ref](#ref)
- [dep](#dep)
- [tags](#tags)

## prereq
- 윈도우, 비주얼 스튜디오 (linux development with c++ 개발 옵션 선택), WSL (Windows Subsystem for Linux)

## desc
- 윈도우 비주얼 스튜디오에서 WSL로 타게팅하여 gnu gcc 컴파일러 및 라이브러리 사용하기.
- 아래 블로그 포스트 참조. (ref 1)

## inst
- instruction
  1. WSL 실행하고 아래 패키지들 설치.
    - build-essential
    - gdbserver
    - openssh-server
  2. 다음 명령으로 ssh 설정 열어서 파일의 `PasswordAuthentication` 옵션을 `yes`로 설정.
  > `sudo nano /etc/ssh/sshd_config`
  3. ssh 키 생성.
  > `sudo ssh-keygen -A`
  4. ssh 시작. (참고: 모든 wsl 셸을 끌 경우 모든 리눅스 프로세스가 꺼지므로 다음에 다시 실행해야함.)
  > `sudo service ssh start`
  5. visual studio에서 c++ 프로젝트 중 cross platform - linux 콘솔 프로젝트 생성.
  6. 디버깅 시도하면 연결하라고 뜸. hostname은 localhost.

- 패키지 설치하다 문제뜨면 `apt-get update` 실행 후 다시 시도.
- 연결된 후 디버깅 시도할 때 `rsync` 및 `pdbserver` 설치하라고 뜨면 wsl에 설치하고 다시 시도.
- `#include` 시 파일을 못찾는다고 뜨면 visual studio의 옵션에서 cross-platform - connection manager - remote headers intellisense에서 
  원격 헤더 캐시 항목 업데이트해주면 프로젝트의 external dependencies가 업데이트됨. (ref 2)

## ref
- https://blogs.msdn.microsoft.com/vcblog/2017/02/08/targeting-windows-subsystem-for-linux-from-visual-studio/
- https://blogs.msdn.microsoft.com/vcblog/2018/04/09/intellisense-for-remote-linux-headers/
- http://www.sysnet.pe.kr/2/0/11390 (한글로 된 다른 블로그 설명)

## dep

## tags
  #windows, #visual-studio, #windows-wsl, #gnu-gcc, #linux, #cpp



--------------------------


 