# git-subtree-push-from-parent-project-to-child

깃 서브트리 부모 프로젝트에서 자식 프로젝트로 푸시하기

--------------------------

- [git-subtree-push-from-parent-project-to-child](#git-subtree-push-from-parent-project-to-child)
  - [desc](#desc)
  - [inst](#inst)
  - [dep](#dep)
  - [ref](#ref)
  - [tags](#tags)

## desc
- git subtree

## inst
> from stackoverflow
>
>On windows the nested command doesn't work:
>```
>git push heroku `git subtree split --prefix pythonapp master`:master --force
>```
>You can just run the nested bit first:
>```
>git subtree split --prefix pythonapp master
>```
>This will (after a lot of numbers) return a token, e.g.
>```
>157a66d050d7a6188f243243264c765f18bc85fb956
>```
>Use this in the containing command, e.g:
>```
>git push heroku 157a66d050d7a6188f243243264c765f18bc85fb956:master --force
>```


## dep
- git

## ref
- [stackoverflow](https://stackoverflow.com/questions/13756055/git-subtree-subtree-up-to-date-but-cant-push)

## tags
  #git, #terminal, #git subtree



--------------------------

 
