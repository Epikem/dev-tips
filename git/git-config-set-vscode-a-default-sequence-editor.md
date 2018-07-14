# git-config-set-vscode-a-default-sequence-editor

비주얼 스튜디오 코드를 깃의 기본 에디터로 설정하기

--------------------------

- [desc](#desc)
- [inst](#inst)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

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

>  This leverages the new `--diff` option you can pass to VS Code to compare two files side by side.
>
>  To summarize, here are some examples of where you can use Git with VS Code:
>
>  `git rebase HEAD~3 -i` allows to interactive rebase using VS Code
>  `git commit` allows to use VS Code for the commit message
>  `git add -p` followed by `e` for interactive add
>  `git difftool <commit>^ <commit>` allows to use VS Code as diff editor for changes
## dep
  - git
  - vscode

## ref
  - [stackoverflow](https://stackoverflow.com/questions/30024353/how-to-use-visual-studio-code-as-default-editor-for-git/36644561)

## tags
  #git, #vscode


----

<!-- license start -->

<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a>
<br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">dev-tips</span> by <a xmlns:cc="http://creativecommons.org/ns#" href="https://www.github.com/epikem/dev-tips" property="cc:attributionName" rel="cc:attributionURL">epikem</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.<br />Permissions beyond the scope of this license may be available at <a xmlns:cc="http://creativecommons.org/ns#" href="https://www.epikem.com" rel="cc:morePermissions">https://www.epikem.com</a>.

<br /><a xmlns:cc="http://creativecommons.org/ns#" href="https://www.github.com/epikem/dev-tips" property="cc:attributionName" rel="cc:attributionURL">epikem</a>에 의해 작성된 <span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">dev-tips</span>는 <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">크리에이티브 커먼즈 저작자표시 4.0 국제 라이선스</a>에 따라 이용할 수 있습니다.<br />이 라이선스의 범위 이외의 이용허락을 얻기 위해서는 <a xmlns:cc="http://creativecommons.org/ns#" href="https://www.epikem.com" rel="cc:morePermissions">https://www.epikem.com</a>을 참조하십시오.

<!-- license end -->
