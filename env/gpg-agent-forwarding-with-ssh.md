# gpg-agent-forwarding-with-ssh

ssh를 이용한 gpg 에이전트 포워딩

--------------------------

- [desc](#desc)
- [inst](#inst)
  - [1. 로컬 머신에서 gpg 퍼블릭 키 export](#1-로컬-머신에서-gpg-퍼블릭-키-export)
  - [2. 로컬 머신의 gpg extra 소켓 경로 확인](#2-로컬-머신의-gpg-extra-소켓-경로-확인)
  - [3. 원격 머신 ssh 접속](#3-원격-머신-ssh-접속)
  - [4. 원격 머신의 gpg 소켓 경로 확인](#4-원격-머신의-gpg-소켓-경로-확인)
  - [5. 원격 머신에서 로컬 머신의 gpg public 키 import](#5-원격-머신에서-로컬-머신의-gpg-public-키-import)
  - [6. 원격 머신의 ssh 서버 설정 (sshd_config) 편집 및 재시작](#6-원격-머신의-ssh-서버-설정-sshd_config-편집-및-재시작)
  - [7. 로컬 머신으로 돌아와서, ssh 원격 포워딩 설정](#7-로컬-머신으로-돌아와서-ssh-원격-포워딩-설정)
  - [8. 원격 머신에 접속하여 포워딩된 gpg secret 키 확인](#8-원격-머신에-접속하여-포워딩된-gpg-secret-키-확인)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc

깃 커밋에 gpg를 이용한 사인 옵션을 설정하게 되면, 깃헙 커밋에 아래와 같은 멋진 배지가 나타난다. (커밋이 확실히 해당 계정 소유자로부터 된 것임을 인증한다고 한다.)

<img width="1204" alt="스크린샷 2021-07-24 오후 9 51 44" src="https://user-images.githubusercontent.com/8192081/126868996-98007835-ef53-4391-ad57-caf7aa1b82a2.png">

그런데, 원격 pc에서 같은 계정으로 gpg 정보 없이 커밋 서명을 사용하려 하면 아래와 같은 (gpg failed to sign the data, failed to write commit object) 에러가 난다:

![image](https://user-images.githubusercontent.com/8192081/126869783-fa7d4e72-ba62-4bd0-8b58-aecbb96dfe52.png)

그래서 해당 컴퓨터에서 커밋 서명을 적용하려면 새로 gpg 키를 만들고 깃헙에서 적용하는 절차를 거쳐야 하는데, 그렇게 하지 않고 gpg 에이전트 포워딩을 이용하여 커밋 서명을 하는 방법이 있다. 해당 방법에 대해 소개한다.

처음에는 깃헙에서 일일히 원격 머신마다 등록하는 것이 귀찮을 것 같아 이 방법을 찾은 것인데, 사실상 이 방법도 자동화하지 않는 이상 상당히 설정해줄 것이 많아 귀찮다..

[dep](##dep)에 있는 버전 기준으로 작성.

## inst

대략적인 절차는 다음과 같다:

1. 로컬 머신에서 gpg 퍼블릭 키 export
2. 로컬 머신의 gpg extra 소켓 경로 확인
3. 원격 머신 ssh 접속
4. 원격 머신의 gpg 소켓 경로 확인
5. 원격 머신에서 로컬 머신의 gpg public 키 import
6. 원격 머신의 ssh 서버 설정 (sshd_config) 편집 및 재시작
7. 로컬 머신으로 돌아와서, ssh 원격 포워딩 설정
8. 원격 머신에 접속하여 포워딩된 gpg secret 키 확인

### 1. 로컬 머신에서 gpg 퍼블릭 키 export

gpg agent 포워딩을 하더라도, 원격 머신에서는 로컬 머신의 공개키는 필요하다.

따라서 먼저 로컬에서 `gpg --list-key` 명령으로 공개키를 내보내기할 키 해쉬값을 찾는다.

![image](https://user-images.githubusercontent.com/8192081/127106919-71b453f6-7358-448c-9e3f-df36bf751625.png)

위 링크에서 `9CEB5CECE6BDEFC3B83204119AE0101FD58C3169`에 해당한다.

그 다음, `gpg --export` 명령으로 해당 키페어의 공개키를 내보내기한다.

`gpg --armor --export <GPG키> > <공개키파일.gpg>`

![image](https://user-images.githubusercontent.com/8192081/127107690-f822e237-50b8-4c48-97e1-7a71afaa4413.png)

위 공개키 파일을 scp 또는 직접 복사로 원격 머신에서 추가할 것이다. (다른 방법도 있을지도)

### 2. 로컬 머신의 gpg extra 소켓 경로 확인

로컬 머신에서 `gpgconf --list-dir agent-extra-socket` 명령으로 소켓 경로를 확인한다.

![image](https://user-images.githubusercontent.com/8192081/127108053-4ef5d4cc-8fd9-4ecc-b0db-c84be8a3e9d9.png)

### 3. 원격 머신 ssh 접속

`ssh <계정>@<원격 머신>` 명령으로 원격 머신에 접속한다.

<img width="297" alt="스크린샷 2021-07-27 오후 3 46 40" src="https://user-images.githubusercontent.com/8192081/127108455-6ac90556-efae-438b-9038-0d65cc762880.png">

### 4. 원격 머신의 gpg 소켓 경로 확인

`gpgconf --list-dir agent-socket` 명령으로 원격 머신의 gpg 에이전트 소켓 경로를 확인한다.

<img width="367" alt="스크린샷 2021-07-27 오후 3 47 57" src="https://user-images.githubusercontent.com/8192081/127108622-f575a6d5-7723-4f14-a2b3-994584066149.png">

### 5. 원격 머신에서 로컬 머신의 gpg public 키 import

`gpg --import <공개키파일.gpg>` 명령으로 로컬 머신의 공개키를 가져온다.

<img width="509" alt="스크린샷 2021-07-27 오후 3 52 50" src="https://user-images.githubusercontent.com/8192081/127109182-2fb03617-291a-4c17-bb30-5373b771500d.png">

이미 등록되어있을 경우 위와 같이 뜨고, 새로 등록할 경우 `changed: 1`로 표시된다.

### 6. 원격 머신의 ssh 서버 설정 (sshd_config) 편집 및 재시작

`sudo vi /etc/ssh/sshd_config` 명령으로 sshd 설정에 들어가서 아래 설정을 적당한 줄에 추가한다:
`StreamLocalBindUnlink yes`

<img width="260" alt="스크린샷 2021-07-27 오후 3 58 22" src="https://user-images.githubusercontent.com/8192081/127109854-5c7bf717-332c-4775-8304-6e5f8d4e7287.png">

그 다음, `sudo systemctl restart sshd.service` 명령 등으로 sshd 서비스를 재시작한다.

<img width="384" alt="스크린샷 2021-07-27 오후 4 00 45" src="https://user-images.githubusercontent.com/8192081/127110142-7d18c047-1e4a-495c-8d87-86ad7f60aa9b.png">


### 7. 로컬 머신으로 돌아와서, ssh 원격 포워딩 설정

`vi ~/.ssh/config` 명령으로 해당 원격 머신에 대한 ssh 설정에 다음 항목을 추가한다:


```
RemoteForward <원격 에이전트 소켓> <로컬 에이전트 extra 소켓>
```

설정하면 아래와 같이 된다.

<img width="675" alt="스크린샷 2021-07-27 오후 4 05 33" src="https://user-images.githubusercontent.com/8192081/127110742-7d8fea12-bc84-4bc0-90c1-70bda13f11f6.png">

### 8. 원격 머신에 접속하여 포워딩된 gpg secret 키 확인

다시 `ssh < ~/.sshconfig의 Host >` 명령으로 원격 머신에 접속한다.

`gpg --list-secret-keys` 명령으로 gpg 시크릿 키가 포워딩된 것을 확인한다.

<img width="481" alt="스크린샷 2021-07-27 오후 4 10 08" src="https://user-images.githubusercontent.com/8192081/127111309-67cff22c-4dd5-454d-816c-a99d499ca904.png">

이렇게 설정해서 잘 작동하다가도 어떨 때는 시크릿 키가 안나오고, 제대로 동작되지 않을 때가 있는데, 재부팅해서 다시 연결하니 성공했다. 정확한 원인은 모르겠다.

## dep
- GnuPG >= v2.1.13
- OpenSSH >= v6.7

## ref
- https://wiki.gnupg.org/AgentForwarding

## tags
- ssh
- env
- gpg
- git
- network

--------------------------