# git-cherry-pick-range-of-commits

----

- [title](#title)
- [desc](#desc)
- [inst](#inst)
- [ref](#ref)
- [tags](#tags)

## title
- 깃 체리픽을 이용하여 특정 범위의 커밋들 가져오기

## desc
- 머지/풀 리퀘스트용 브랜치와 작업 브랜치를 나누어서 작업할 때, 테스트용 작업 브랜치에서 만들어진 결과 커밋들을 체리픽을 이용하여 한 번에 가져올 수 있다.
- 당연히 커밋 자체는 리베이스처럼 대상 브랜치 위에 새로 써진다.

## inst

- `git cherry-pick A^..B`와 같이 사용하는데, A..B로 하면 A 다음 커밋부터 합쳐지는 것에 주의한다.

1. 다음과 같이 사용한다.

>shell
```
git checkout <대상 브랜치>
git cherry-pick <합쳐질 커밋 시작>^..<합쳐질 커밋 끝>
```

예:

>shell
```sh
git cherry-pick fix-134-work~3..fix-134-work~1 # fix-134-work 브랜치의 HEAD로부터 2번째 커밋(~3이므로 HEAD~3 제외)부터 1번째 커밋까지 합쳐온다.
```


## ref
- (https://stackoverflow.com/questions/1994463/how-to-cherry-pick-a-range-of-commits-and-merge-into-another-branch)

## tags
- git
- cli




--------------------------

 
