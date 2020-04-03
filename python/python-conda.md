# python-conda

windows python conda usage (miniconda)

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

## prerequisite

- scoop

## desc
(윈도우) 파이썬에서 conda 사용법 (miniconda)

## inst

### 1. installing virtualenv

> 📂 `terminal.ps`
```ps
# install miniconda3
scoop install miniconda3
# after install
conda install -n root -c pscondaenvs pscondaenvs
```

### 2. creating a virtualenv

> 📂 `terminal.ps`
```ps
# > conda create -n (env-name)
# example:
conda create -n dl
```

### 3. activating a virtualenv

> 📂 `terminal.ps`
```ps
# > activate (env-name)
# example:
activate dl
```

* check which python i'm using with this command :

> 📂 `terminal.ps`
```ps
scoop which python
```

### leaving the virtualenv
```ps
deactivate
```

## dep

## ref

## tags
  #python, #pip, #virtualenv, #venv, #conda

--------------------------


 