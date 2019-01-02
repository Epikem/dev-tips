# git-pull

----

- [title](#title)
- [desc](#desc)
- [inst](#inst)
- [ref](#ref)
- [tags](#tags)

## title
- 깃 끌어오기 사용하기

## desc
- git 기본적인 끌어오기 사용방법.

## inst
1. make sure remote origin is registered using below command

  > terminal
  > `git remote`


1.1. if no origin registered, add a remote origin with below command


  > terminal
  > `git remote add origin <remote git url>`
  2. pull

  3. 그리고 나서 checkout -f를 사용해 로컬 변경을 덮어쓰고 리모트 브랜치를 가져올 수 있다.
  >shell
  `git checkout -f master`

4. 만약 "there is no tracking information ..." 관련 경고가 뜬다면, 나온 지시대로 아래 명령을 수행하자.
>shell
`git pull <remote> <branch>`

또는 현재 브랜치에 대해 자동으로 리모트 브랜치를 가져오려면 아래 명령을 사용한다 :
>shell
`git branch -u <remote>/<remote branch>`

다른 브랜치에 대해 하려면 :
>shell
`git branch -u <remote>/<remote branch> <local branch>`

5. 아래와 같은 편하게 해 주는 옵션도 있다.
>shell
`git pull --rebase`
이 명령을 쓰면 지금까지 쓴 로컬 역사를 새로 가져오는 리모트의 역사 위로 옮겨준다고 하는 것 같다. 매우 편할 듯. (테스트 해봐야 함.)

## ref
- (https://stackoverflow.com/questions/1125968/how-do-i-force-git-pull-to-overwrite-local-files)

## tags
  #git




--------------------------

 
