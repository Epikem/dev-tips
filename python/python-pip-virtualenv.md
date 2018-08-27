# python-pip-virtualenv

파이썬에서 pip virtualenv 사용법

--------------------------

- [desc](#desc)
- [inst](#inst)
  - [1. installing virtualenv](#1-installing-virtualenv)
  - [2. creating a virtualenv](#2-creating-a-virtualenv)
  - [3. activating a virtualenv](#3-activating-a-virtualenv)
  - [leaving the virtualenv](#leaving-the-virtualenv)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)


## desc
- 파이썬에서 virtualenv의 사용법.

## inst

### 1. installing virtualenv

> On macOS and Linux:
> 
> `> python3 -m pip install --user virtualenv`
> 
> On Windows:
> 
> `> py -m pip install --user virtualenv`

### 2. creating a virtualenv

> On macOS and Linux:
> 
> `> python3 -m virtualenv env`
> 
> On Windows:
> 
> `> py -m virtualenv env`

### 3. activating a virtualenv

> On macOS and Linux:
> 
> `> source env/bin/activate`
> 
> On Windows:
> 
> `> .\env\Scripts\activate`

* check which python i'm using with this command :

> On macOS and Linux:
> ```
> > which python
> .../env/bin/python
> ```
> On Windows:
> 
> ```
> > where python
> .../env/bin/python.exe
> ```

### leaving the virtualenv
```
deactivate
```

## dep

## ref
  - [python doc](https://packaging.python.org/guides/installing-using-pip-and-virtualenv/)
  <!-- - [stackoverflow](https://stackoverflow.com/questions/)
  - [github](https://github.com/Epikem) -->

## tags
  #python, #pip, #virtualenv, #venv



--------------------------


<!-- license start -->

<a rel="license" href="http://creativecommons.org/licenses/by/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by/4.0/88x31.png" /></a>
<br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">dev-tips</span> by <a xmlns:cc="http://creativecommons.org/ns#" href="https://www.github.com/epikem/dev-tips" property="cc:attributionName" rel="cc:attributionURL">epikem</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">Creative Commons Attribution 4.0 International License</a>.<br />Permissions beyond the scope of this license may be available at <a xmlns:cc="http://creativecommons.org/ns#" href="https://www.epikem.com" rel="cc:morePermissions">https://www.epikem.com</a>.

<br /><a xmlns:cc="http://creativecommons.org/ns#" href="https://www.github.com/epikem/dev-tips" property="cc:attributionName" rel="cc:attributionURL">epikem</a>에 의해 작성된 <span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">dev-tips</span>는 <a rel="license" href="http://creativecommons.org/licenses/by/4.0/">크리에이티브 커먼즈 저작자표시 4.0 국제 라이선스</a>에 따라 이용할 수 있습니다.<br />이 라이선스의 범위 이외의 이용허락을 얻기 위해서는 <a xmlns:cc="http://creativecommons.org/ns#" href="https://www.epikem.com" rel="cc:morePermissions">https://www.epikem.com</a>을 참조하십시오.

<!-- license end -->