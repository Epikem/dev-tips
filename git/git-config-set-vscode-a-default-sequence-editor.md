# git config set vscode a default sequence editor

----
[TOC]

## title

 비주얼 스튜디오 코드를 깃의 기본 에디터로 설정하기

## desc
  깃 diff, commit message 등의 명령에서 vim 인터페이스 대신 vscode를 기본 에디터로 사용

## inst
1. 터미널 열기.
2. code --help 정상 출력되는지 확인.
3. git config --global core.editor "code --wait"
4. git config --global -e
5. 열리는 깃헙 글로벌 에디터 설정에 다음 내용 추가.

```
  [diff]
      tool = default-difftool
  [difftool "default-difftool"]
      cmd = code --wait --diff $LOCAL $REMOTE
```

6. 끝.

  This leverages the new `--diff` option you can pass to VS Code to compare two files side by side.

  To summarize, here are some examples of where you can use Git with VS Code:

  `git rebase HEAD~3 -i` allows to interactive rebase using VS Code
  `git commit` allows to use VS Code for the commit message
  `git add -p` followed by `e` for interactive add
  `git difftool <commit>^ <commit>` allows to use VS Code as diff editor for changes
## dep
  - git
  - vscode

## ref
  - [stackoverflow](https://stackoverflow.com/questions/30024353/how-to-use-visual-studio-code-as-default-editor-for-git/36644561)

## tags
  [#git](#title), #github, #vscode, #howto


----
<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="크리에이티브 커먼즈 라이선스" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>

<a href='https://github.com/Epikem' target='_blank'>Epikem</a>이 작성한 이 저작물은

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">크리에이티브 커먼즈 저작자표시-비영리-동일조건변경허락 4.0 국제 라이선스</a>에 따라 이용할 수 있습니다.
