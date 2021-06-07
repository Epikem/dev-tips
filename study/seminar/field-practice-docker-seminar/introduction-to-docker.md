
# docker 세미나 준비

## 메타 준비

중간 리뷰 가능시간:
- 화 / 목 (목 2~4 제외)

### ref:
- https://rinae.dev/posts/things-to-know-when-you-prepare-presentation-first-time
- https://zzsza.github.io/diary/2019/10/20/helping-presentation/

### 기본
ㄱ) 발표를 통해 어떤 내용을 전달할 것인가?
ㄴ) 발표의 예상 청중은?
ㄷ) 발표의 예상 난이도는? 난이도가 있다면 어느 정도 알아야 수월하게 들을 수 있는가?
ㄹ) 희망하는 예상 시간대는?

### 초안 피드백
1. 전달하고 싶은 내용을 한줄로 설명 (내용을 관통하는 일관적 주제)
   1. -> 도커 시작하기: 간단한 소개와 사용법
2. 내용 단순 나열이 아닌 스토리가 있는지? (->설명인데 꼭 필요할까?)
3. 유용하게 얻어갈 내용이 있는지
   1. 사진찍을 만한?
   2. 큰 이야기가 끝나면 한장 요약

### 최종 피드백
1. 시간 안에 마무리 가능한지:
   1. 



## 본문

### docker 가 나오게 된 계기
어떤 기술을 배우기 전에, 왜 쓰는지 알고 배우면 더 동기부여도 된다. 도커를 왜 쓰는지 배우기 전에 도커가 없던 때의 불편한 점을 생각해보자.


#### 기존 기술의 한계/문제점
웹 서비스 
- 소프트웨어를 실행하여 기능을 제공
- 보통 클라이언트와 서버가 필요
- 소스로부터 빌드하는 스크립트 작성
-> 수많은 언어, 라이브러리, 프레임워크, 아키텍쳐 등의 도구 간 호환성 문제, 유지보수 어려움
-> 'it works on my machine' 문제 발생
-> 어떻게 개발/운영 환경을 맞출까?? 운영이 ubuntu 서버인데 개발자가 맥 유저라면 등..
-> 가상머신 도입
- virtualbox, vmware 등으로 가상화
- 하이퍼바이저를 이용하여 게스트 운영체제를 구동
- 문제는, 무겁다
- 전가상화, 반가상화?, kvm, xen : https://subicura.com/2017/01/19/docker-guide-for-beginners-1.html
- 여전히 무겁다.

- ref
  - https://www.docker.com/why-docker

- 그래서 도커를 도입.
- 가상화와 어떻게 다른지는 곧 설명. 먼저 도커의 역사부터 소개


- [ ] 정리 문제:
  - [ ] 가상화가 왜 필요한지 좀더 간결하게 설명 필요
  - [ ] 정말로 요즘 가상화를 대신해서 도커가 쓰이나?
  - [ ] 클라우드나, msa나, 호스팅 서비스와 관련지어야 하지는 않는가?
  - [x] 일단 구성 자체가 정리가 안되어 있다.

서버관리는 좀 협소하게 보는 것 같고, 결국은 서비스 제공, 앱 개발 관점에서 서비스를 제공하기 위한 서버를 관리하는 데 문제가 생기는 것 아닌가?

소스 코드 -> 빌드 -> 서버에 배포 -> 서비스 실행

그런데 이 사이클에 왜 도커나 가상화가 필요할까?
운영체제, 라이브러리 및 프레임워크 버전 등 환경에 따라 같은 소스 코드여도 성공할 수도, 실패할 수도 있다.
- 해결 방법?
  - 1. 환경마다 세팅 -> 변경사항 등 이슈 발생마다 테스트 필요, 유지보수 어려워짐
  - 2. 환경을 통일 -> 운영환경 / 개발환경을 어떻게 통일할 것인가?
    -> 가상화 도입


- [ ] 궁금한 부분:
  - [ ] 다른 아키텍처로도 이미지 빌드 가능한가?

### docker 란?

#### 역사
- docker는 2013년 파이콘 세션에서 처음 발표됨

#### 개념
- 컨테이너 기반 가상화? 기술
- 사전적 의미 : 부두 노동자 -> 소프트웨어 단위를 추상화하여 담은 컨테이너를 실어나르고 관리하는 역할

https://hoon93.tistory.com/41


### docker 원리/기술 요약

#### 원리 - 기존 가상화와 비교
- 가상화:
  - 게스트 OS 설치 ->
    - 속도가 느림
    - 이미지 용량이 큼
- 도커:
  - 도커 엔진 설치, 게스트 OS 미설치 -> 라이브러리,프로그램만 설치, OS는 호스트와 공유
    - 속도가 빠름
    - 이미지 용량이 줄어듬
  - 그리고, 도커는 이미지, 레지스트리 등의 통해 편의 관리 기능을 제공

#### 기술
  - chroot: 프로세스에 새로운 루트 지정
  - namespace: 공간 격리, what you can see
    - syscall로 생성
    - pid, mounts, network, uids, ipc ...
  - cgroup: 자원 제한, what you can use
    - fileSystem 인터페이스?
    - memory, cpu, i/o, ...
    - ? cgroup 없는 맥/윈도우에서는 어떻게 하는건가?
    - ref: https://developer.apple.com/documentation/hypervisor
    - https://www.thorsten-hans.com/docker-container-cpu-limits-explained/
    - https://collabnix.com/how-docker-for-mac-works-under-the-hood/
    - https://www.youtube.com/watch?v=8fi7uSYlOdc
    - https://medium.com/@BeNitinAgarwal/understanding-the-docker-internals-7ccb052ce9fe

- ref: 
- https://tomatohj.tistory.com/39
- https://www.youtube.com/watch?v=8fi7uSYlOdc

### 요소들
도커의 각 요소들, 이후 실습에서 재설명할것이므로 간략하게 설명

- 도커 데몬
  - api 요청 처리
- 도커 클라이언트
  - `docker` cli 및 `docker-compose`
- 도커 레지스트리
  - 도커 이미지 저장소, DockerHub가 기본 원격 저장소.
  - `pull, run` -> 이미지 가져옴
  - `push` -> 이미지 업로드

#### 도커 객체 (docker objects)
- 이미지
  - 도커 컨테이너를 만드는 읽기 전용 템플릿
  - 각 명령이 이미지에 '레이어'를 만듬.
  - 'Dockerfile'을 변경하여 이미지를 재빌드하면 바뀐 부분부터 다시 만들어짐
- 컨테이너
  - 이미지의 실행 상태

- 이미지
  - 파일 시스템과 라이브러리 조합
  - 컨테이너 생성 템플릿
- 컨테이너
  - 기본 컨테이너:
    - 알파인 리눅스 https://namu.wiki/w/Alpine%20Linux
      - apk를 패키지 매니저로 사용
      - cve scan이 실패할 수 있음. https://www.udemy.com/tutorial/docker-mastery-for-nodejs/when-to-use-alpine-debian-or-centos-images/
- 아키텍쳐:
  - 전체적 도커 아키텍쳐: ![(공식 설명 발췌 이미지, apache 라이센스)](https://docs.docker.com/engine/images/architecture.svg) 
  - (공식 설명 발췌 이미지, apache 라이센스)

- ref
  - https://devowen.com/249

### 설치 방법
- [ ] [docker engine 설치 과정](https://docs.docker.com/engine/install/)
  - [ ] Mac & Windows : Docker Desktop 설치

* FALLBACK method: https://www.docker.com/play-with-docker


### 사용방법
- docker run hello world
- docker image ls
  - docker commit
- docker container ls
  - docker diff
- docker volume
- Dockerfile
  - https://goinbigdata.com/docker-run-vs-cmd-vs-entrypoint/

간단 예제
ex) hello world



ex) spring-boot 웹 서버를 docker container 로 띄우기
- https://spring.io/guides/gs/spring-boot-docker/

### 더 알아보기
- 도커로 할 수 있는것들
  - sync
- 주의점
  - 보안 - docker secret
- 도커 메타 문서 모음집
  - https://github.com/remotty/documents.docker.co.kr

### etc
- nettop
- `ps aux | grep hyper` -> 메모리 할당량 확인
- `sysctl kern.hv_support` -> 가상화 지원 여부 확인

#### 회사에 적용

- https://github.com/mobigen/docker
- d



### 참고
- https://subicura.com/2016/06/07/zero-downtime-docker-deployment.html
- https://tech.ssut.me/what-even-is-a-container/
- https://apple.stackexchange.com/questions/136335/os-level-virtualization-containers-for-os-x
- https://www.thorsten-hans.com/docker-container-cpu-limits-explained/
- https://linuxcontainers.org/lxc/introduction/
- https://medium.com/@harsh.manvar111/lxc-vs-docker-lxc-101-bd49db95933a
- https://iamjjanga.tistory.com/50
- https://appletoolbox.com/seeing-error-operation-not-permitted-in-macos-mojave/#:~:text=Restart%20your%20Mac%20and%20open,should%20be%20back%20in%20business
- https://www.slideshare.net/dotCloud/why-docker
- https://www.slideshare.net/pyrasis/docker-fordummies-44424016
- https://ssowonny.medium.com/vs-code%EB%A1%9C-%EC%BB%A8%ED%85%8C%EC%9D%B4%EB%84%88-%EC%95%88%EC%97%90%EC%84%9C-%EA%B0%9C%EB%B0%9C%ED%95%98%EA%B8%B0-d8ed0950d69a
- https://k21academy.com/docker-kubernetes/docker-image-and-layer-overview-for-beginners/#3


## tags
- docker