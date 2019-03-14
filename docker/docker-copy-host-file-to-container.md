# docker-copy-host-file-to-container

도커에서 호스트의 로컬 파일을 컨테이너로 복사하기

--------------------------

- [inst](#inst)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## inst
> source: [ref 1](#ref)


`docker cp` 커맨드를 이용한다. 호스트<->컨테이너 양방향으로 쓸 수 있다.

> 📂 `terminal.ps1`
```ps1
docker cp myfile.txt mycontainer:/myfilepasted.txt
docker cp mycontainer:/myfilepasted.txt myfile.txt
```

폴더 내의 여러 파일을 한 번에 옮기는 것도 가능하다. (복사 대상은 타겟의 파일들이 들어갈 폴더 이름으로 지정)
> 📂 `terminal.ps1`
```ps1
docker cp src/. mycontainer:/target
docker cp mycontainer:/src/. target
```


## dep

## ref
  - [stackoverflow]([https://stackoverflow.com/questions/](https://stackoverflow.com/questions/22907231/copying-files-from-host-to-docker-container))

## tags
  #docker



--------------------------

 