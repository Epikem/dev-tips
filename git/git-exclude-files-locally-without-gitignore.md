# git-exclude-files-locally-without-gitignore

----
- [title](#title)
- [desc](#desc)
- [inst](#inst)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## title

 깃에서 gitignore 쓰지 않고 파일/폴더 제외하기

## desc
  깃에서 .gitignore파일로 공유하지 않고서 프로젝트에서 나만 쓸 파일 등이 있을 경우, 그 파일들을 제외해야 하지만 gitignore에 포함해서도 안 된다.
  아래는 이 경우의 해결 방법이다.

## inst
  1. 대상 프로젝트의 .git/info/exclude 파일을 찾거나 없으면 만든다.
  2. .gitignore 쓰듯이 제외할 경로를 작성한다.
  
## dep
  - git

## ref
  - [stackoverflow](https://stackoverflow.com/questions/653454/how-do-you-make-git-ignore-files-without-using-gitignore)

## tags
  #git, #gitignore


----

 
