# gcp-basic-project-setup-tutorial-compute-engine-quick-start

구글 클라우드 플랫폼 기본 프로젝트 셋업 가이드

--------------------------

- [desc](#desc)
- [inst](#inst)
  - [백엔드 인스턴스에 연결 (가이드에서 가져옴)](#백엔드-인스턴스에-연결-가이드에서-가져옴)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc
- gcp에서 기본 프로젝트 셋업 방법. Compute Engine 빠른 시작 가이드 보고 따라하면서 정리함.
- 다음과 같은 구성을 하게 된다:

> 이 빠른 시작에서는 Compute Engine을 사용하여 2단계 애플리케이션을 만들어 봅니다. 프런트엔드 VM에서 Node.js 할 일 웹 앱을 
> 실행하고 백엔드 VM에서는 MongoDB를 실행하는 방식입니다.
>
> 이 가이드에서 설명하는 내용은 다음과 같습니다.
>
>  - 두 개의 VM 생성 및 구성 중
>
>  - 방화벽 규칙 설정
>
>  - SSH를 사용하여 VM에 패키지 설치

## inst
1. 프로젝트 만들기
2. Compute Engine에서 백엔드 및 프론트엔드 VM 인스턴스 생성. 컨테이너 관련 체크박스는 냅두고, 부딩 디스크 이미지로 우분투 사용. HTTP 트래픽 허용 설정.
3. Cloud Shell을 열어 아래와 같은 절차를 통해 백엔드 인스턴스에 데이터베이스를 설치하고 서비스를 실행한다.

### 백엔드 인스턴스에 연결 (가이드에서 가져옴)
>    인스턴스에 연결
>
>    다음 명령어를 입력하여 VM에 SSH를 설정합니다. Cloud Shell에서 처음으로 SSH를 사용한다면 비공개 키를 만들어야 합니다. 앞서 생성한 인스턴스의 영역과 이름을 입력합니다.
> ``` 
>    gcloud compute --project \
>        "my-project-4859-for-practic" ssh \
>        --zone <backend-zone> \
>        <backend-name>
>```
>    백엔드 데이터베이스 설치
>
>    백엔드 인스턴스에 SSH를 연결했으면 이제 다음 명령어를 사용해 백엔드 데이터베이스를 설치합니다.
>
>    패키지를 업데이트하고 MongoDB를 설치합니다. 계속할지 묻는 메시지가 표시되면 Y를 입력합니다.
>```
>    sudo apt-get update
>
>    sudo apt-get install mongodb
>```
>    데이터베이스 실행
>
>    MongoDB 서비스는 설치 당시 시작되었습니다. 실행 방식을 변경하려면 서비스를 중지해야 합니다.
>```
>    sudo service mongodb stop
>```
>    MongoDB를 위한 디렉토리를 만든 다음 포트 80을 통해 백그라운드에서 MongoDB 서비스를 실행합니다.
>```
>    sudo mkdir $HOME/db
>
>    sudo mongod --dbpath $HOME/db --port \
>        80 --fork --logpath \
>        /var/tmp/mongodb
>```
>    이후 exit 명령어를 사용해 SSH 세션을 종료합니다.
>```
>    exit
>```


## dep

## ref

## tags
  #cloud, #gcp



--------------------------

 