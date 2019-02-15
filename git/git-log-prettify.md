# git-log-prettify

깃 checkout으로 특정 파일의 로컬 변경 되돌리기
 
--------------------------

- [desc](#desc)
- [inst](#inst)
- [ref](#ref)
- [tags](#tags)


## desc


## inst
아래 내용을 git config 를 열어서 추가한다.

```git-config
[log]
  date = relative
[format]
	pretty = format:%C(auto,yellow)%h%C(auto,magenta)% G? %C(auto,blue)%>(12,trunc)%ad %C(auto,green)%<(7,trunc)%aN%C(auto,reset)%s%C(auto,red)% gD% D
```

## ref
- https://stackoverflow.com/questions/1441010/the-shortest-possible-output-from-git-log-containing-author-and-date


## tags
  #git


  --------------------------

 



ref : 
