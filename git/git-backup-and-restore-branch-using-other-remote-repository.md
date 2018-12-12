# git-backup-and-restore-branch-using-other-remote-repository

다른 원격 저장소에 백업해 둔 브랜치를 다시 가져온 다음, 다시 그 브랜치가 가리키는 원격 저장소 바꾸기

--------------------------

- [desc](#desc)
- [inst](#inst)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc
- 다른 원격 저장소에 백업해 둔 브랜치를 다시 가져온 다음, 다시 그 브랜치가 가리키는 원격 저장소 바꾸기

## inst

1. 먼저 `git remote add backup ...`으로 백업 원격 저장소를 추가한다.
2. `git fetch backup`으로 백업 원격 저장소의 데이터를 가져온다.
3. `git checkout -b branchName backup/backupBranchName` 으로 백업 원격 저장소의 backupBranchName 브랜치로 로컬 브랜치 branchName를 만든다.
4. 이제 이 브랜치가 다른 원격 저장소를 가리키게 해야 한다.
`git branch branchName -u origin/originBranchName` 으로 브랜치의 포인터를 origin 원격 저장소의 originBranchName 브랜치로 바꾼다.

## dep
- git@1.8.0+

## ref

## tags
  #git



--------------------------


 