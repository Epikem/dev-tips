powershell-get-file-list-of-a-directory
=====

- [title](#title)
- [desc](#desc)
- [inst](#inst)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## title
- 파워셸 폴더에서 파일 리스트 가져오기

## desc
- Get file list of a directory

## inst
below gets file list recursivly and with filter.

`Get-ChildItem -Path $path -Recurse -Filter "*sample*"`

응용하면 폴더 내 조건에 맞는 모든 파일에 대해 스크립트를 실행하게 할 수 있다.

## dep
  - Windows 10
  - powershell

## ref
  - [stackoverflow](https://stackoverflow.com/questions/44825746/list-file-names-in-a-folder-matching-a-pattern-excluding-file-content)

## tags
  #windows, #powershell



  ----
  <a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="크리에이티브 커먼즈 라이선스" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a>

  <a href='https://github.com/Epikem' target='_blank'>Epikem</a>이 작성한 이 저작물은

  <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">크리에이티브 커먼즈 저작자표시 4.0 국제 라이선스</a>에 따라 이용할 수 있습니다.
