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


 