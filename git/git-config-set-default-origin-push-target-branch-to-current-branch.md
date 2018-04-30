# git-config-set-default-origin-push-target-branch-to-current-branch

## desc
  - 깃 설정에서 기본 원격 푸시 대상을 현재 브랜치로 설정하기

  이것을 해두면 `git push --set-upstream origin/master`를 더 이상 쓰지 않아도 된다.
  현재 브랜치를 기준으로 자동으로 같은 원격 브랜치에 푸쉬하도록 설정한다.

  >  push.default
  >
  >  Defines the action git push should take if no refspec is explicitly given.
  >
  >  push.default = current - push the current branch to update a branch with the same name on the receiving end. Works in both central and non-central workflows.


## inst
    To add to your global Git configuration, run this on the command line:

    >$ git config --global push.default current



### ref
  - [Stackoverflow](https://stackoverflow.com/questions/1519006/how-do-you-create-a-remote-git-branch/27185855#27185855)

### dep
  - git@2.0+

### tag
  #stackoverflow, #git, #git-config



----
<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="크리에이티브 커먼즈 라이선스" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>

<a href='https://www.facebook.com/hanmomhanda' target='_blank'>Epikem</a>이 작성한 이 저작물은

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">크리에이티브 커먼즈 저작자표시-비영리-동일조건변경허락 4.0 국제 라이선스</a>에 따라 이용할 수 있습니다.
