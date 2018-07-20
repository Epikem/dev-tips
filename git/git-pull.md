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

<!-- license start -->

<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a>
<br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">dev-tips</span> by <a xmlns:cc="http://creativecommons.org/ns#" href="https://www.github.com/epikem/dev-tips" property="cc:attributionName" rel="cc:attributionURL">epikem</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.<br />Permissions beyond the scope of this license may be available at <a xmlns:cc="http://creativecommons.org/ns#" href="https://www.epikem.com" rel="cc:morePermissions">https://www.epikem.com</a>.

<br /><a xmlns:cc="http://creativecommons.org/ns#" href="https://www.github.com/epikem/dev-tips" property="cc:attributionName" rel="cc:attributionURL">epikem</a>에 의해 작성된 <span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">dev-tips</span>는 <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">크리에이티브 커먼즈 저작자표시 4.0 국제 라이선스</a>에 따라 이용할 수 있습니다.<br />이 라이선스의 범위 이외의 이용허락을 얻기 위해서는 <a xmlns:cc="http://creativecommons.org/ns#" href="https://www.epikem.com" rel="cc:morePermissions">https://www.epikem.com</a>을 참조하십시오.

<!-- license end -->
