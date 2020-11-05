# git-secret

gpg와 깃 secret을 사용하여 비밀 파일 관리하기

--------------------------

- [desc](#desc)
- [inst](#inst)
	- [셋업](#셋업)
	- [보내기](#보내기)
		- [방법 1](#방법-1)
		- [방법 2](#방법-2)
	- [다른 사용자 추가](#다른-사용자-추가)
	- [키 서버로부터 다른 사용자 추가](#키-서버로부터-다른-사용자-추가)
	- [보내는 부분 영상](#보내는-부분-영상)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc
- git secret 및 gpg를 이용하여 비밀 파일을 git으로 관리

## inst

### 셋업

1. `git-secret` 설치
`sudo apt install git-secret -y`
2. `cd <path>`로 git 저장소 위치로 간다
3. git 저장소에서 `git secret init` 실행
2. `gpg --gen-key` 또는 `gpg --full-gen-key` 를 사용하여 자신의 이메일로 새 `gpg`키를 만든다
> 만약 entropy에서 계속 걸린다면, `sudo apt-get install haveged -y` 설치
> `watch -n1 cat /proc/sys/kernel/random/entropy_avail` 명령으로 시스템 엔트로피 확인 가능 (계속 올라야 한다.)
3. `git secret tell <email>` 명령으로 사용자 추가.
4. `git secret add <file-path>` 명령으로 보호할 파일 추가.
5. `git secret hide` 명령으로 암호화
6. `git secret reveal` 명령과, 패스워드 입력으로 복호화

hide로 만들어진 `.secret` 파일을 git에 올려서 관리하면 된다. 대신 파일을 업데이트할 때마다 반드시 `git secret hide`명령으로 업데이트한 후 커밋해야 한다.

### 보내기
1. `git-secret` 설치
`sudo apt install git-secret -y`
2. `gpg --gen-key` 또는 `gpg --full-gen-key` 를 사용하여 자신의 이메일로 새 `gpg`키를 만든다

> 만약 entropy에서 계속 걸린다면, `sudo apt-get install haveged -y` 설치
> `watch -n1 cat /proc/sys/kernel/random/entropy_avail` 명령으로 시스템 엔트로피 확인 가능 (계속 올라야 한다.)

#### 방법 1
3. `gpg -a --export <email>`로 자신의 공개키를 출력한다.
4. 해당 공개키를 복사하여 공유한다.

#### 방법 2
3. `gpg --list-keys`로 키아이디 확인
4. `gpg --keyserver pgp.key-server.io --send-key 키아이디`로 자신의 키 업로드

### 다른 사용자 추가
1. 다른 사용자의 `gpg` public key를 받는다
2. `gpg --import <key-name>`으로 등록
3. `git secret tell <email>`로 사용자 등록
4. `git secret hide`로 파일을 다시 암호화

### 키 서버로부터 다른 사용자 추가
1. `gpg --keyserver <url> --recv-keys <server-key-id>`

### 보내는 부분 영상

[![asciicast](https://asciinema.org/a/YLlEQ3IOgkc3I7OBA8kKgF8vL.png)](https://asciinema.org/a/YLlEQ3IOgkc3I7OBA8kKgF8vL)

## dep
- git
- gpg

## ref
- https://hyunto.github.io/2018/12/11/git-secret/

## tags
  \#git, \#terminal, \#git-secret, \#gpg 


 