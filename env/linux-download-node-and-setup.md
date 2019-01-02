# linux-download-node-and-setup

linux 머신 계열별 node 설치

--------------------------

- [desc](#desc)
- [inst](#inst)
  - [debian (ubuntu, )](#debian-ubuntu-)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc
- description

## inst

아래와 같이 한 줄이면 된다. 그런데 주소가 리눅스 계열별로 다르다.

### debian (ubuntu, )
curl -sL https://deb.nodesource.com/setup_5.x | sudo -E bash -

이렇게 하면 위 링크에서 node 5를 받아서 설치 파일로 저장하지 *않고* 바로 설치한다.

그런데, 아래 링크에서 보니 이런걸 더 쉽게 설치하게 해주는 `Snap`이라는 것이 있다. 

`sudo snap install node --classic --channel=8` 이렇게 하면 바로 node, npm, yarn이 설치된다. 버전 변경도 가능하다. 근데 git은 이걸로 설치가 안 되는걸로 보아 버전 있는것만 관리하는 건가?
 

## dep

## ref
  - [stackExchange](https://askubuntu.com/questions/891872/pipe-to-sudo-e-bash)
  - https://github.com/nodesource/distributions


## tags
  #linux, #debian, #bash, #shell



--------------------------


 