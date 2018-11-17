# git-pull-with-force

깃 강제로 끌어오기

--------------------------

- [desc](#desc)
- [inst](#inst)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc
- pull a git repository branch discarding all local changes

## inst
- instruction
  1. `git fetch --all`
  2. `git reset --hard origin/<branch_name>`
- (2018-10-16 추가.) 위 명령으로는 추가되지 않았고 변경되지 않은 로컬 파일은 지워지지 않고 그대로 남아있는다.
예를 들어 로컬에서 리모트에 앞서 나가서 역사에 없던 A, B를 생성, B, C는 변경했을 때(C는 역사에 있던 파일), 다시 리모트로 위 명령으로 되돌린다면 A와 B는 로컬 내용 그대로 남아있고 C만 마지막 역사 버전으로 되돌려진다. 즉 `git reset --hard`는 untrackted 파일은 건들지 않는다.

그렇다면 untracked 파일까지 포함해서 되돌리려면? 아래 명령을 사용하면 된다. (ref 1 참조. 되돌릴 수 없다.)
  1. `git reset --hard HEAD`
  2. `git clean -f -d`
  3. `git pull`
위 명령에서 `git clean`이 untracked file들을 제거하게 된다. 다시 `git pull`이 필요한지는 잘 모르겠다.
  
## dep

## ref
  - [stackoverflow:how-do-i-force-git-pull-to-overwrite-local-files](https://stackoverflow.com/questions/1125968/how-do-i-force-git-pull-to-overwrite-local-files)

## tags
  #git, #stackoverflow, #git-pull

 