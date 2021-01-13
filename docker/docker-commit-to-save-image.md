# docker-commit-to-save-image

도커에서 변경된 컨테이너를 이미지로 만들어 저장하기

--------------------------

- [inst](#inst)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## inst
> source: [ref 1](#ref)


`docker commit` 커맨드를 쓰면 컨테이너를 이미지로 만들 수 있다.

> 📂 `terminal`
```shell
#docker commit <containerName or ID> <imageName>:<tag>
docker commit epic_banzai epikem/ros:capstone-v2

docker push

denied: requested access to the resource is denied
unauthorized: authentication required
```

만약 위와 같이 나오면 로그인이 필요한 것이다.

> 📂 `terminal`
```shell
epikem@EpikemPC:~$ docker login
Login with your Docker ID to push and pull images from Docker Hub. If you don't have a Docker ID, head over to https://hub.docker.com to create one.
Username: epikem
Password:
WARNING! Your password will be stored unencrypted in /home/epikem/.docker/config.json.
Configure a credential helper to remove this warning. See
https://docs.docker.com/engine/reference/commandline/login/#credentials-store

Login Succeeded
```


## dep

## ref
  - [docker doc](https://docs.docker.com/engine/reference/commandline/commit)

## tags
  #docker



--------------------------

 