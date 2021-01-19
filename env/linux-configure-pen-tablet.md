# linux-configure-pen-tablet

linux 펜 타블렛 설정

--------------------------

- [desc](#desc)
- [inst](#inst)
  - [debian (ubuntu, )](#debian-ubuntu-)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc
- 앞부분 설정 생략되어있음. ubuntu, gaomon 타블렛 기준.

## inst

- S56K 타블렛 드라이버 우분투에 설치 성공. aspect ratio 적용 완료

xsetwacom 명령어를 이용한다.

`xsetwacom list`로 장치 이름 확인.

> 📂 `terminal.sh`
```sh
epikem@epikem-pc:~$ xsetwacom list
Tablet Monitor Pad pad          	id: 14	type: PAD       
Tablet Monitor Pen stylus       	id: 13	type: STYLUS  
```

그 후 `xsetwacom set`으로 영역 설정.

> 📂 `terminal.sh`
```sh
epikem@epikem-pc:~$ xsetwacom set "Tablet Monitor Pen stylus" Area 0 0 25186 14130
xsetwacom set "Tablet Monitor Pen stylus" Area 0 0 25186 14130
```

영역 비율을 맞추려면 수동으로 해야 한다. xrandr로 화면 해상도는 확인 가능.

`xsetwacom`이 여러 매개변수를 가지는데, `Area`매개변수로 타블렛의 영역을 설정 가능하고, `MapToOutput` 매개변수로 모니터에 매핑할 수 있다.

어느 모니터인지 모르면 `xrandr --listactivemonitors` 명령으로 확인 가능한데, 그냥 `HEAD-0`이 첫번째 모니터를 나타내므로 이를 써도 된다.



## dep

## ref
- https://unix.stackexchange.com/questions/318066/lubuntu-16-04-xsetwacom-unable-to-find-an-output-dvi-i-0

## tags
  \#linux, \#debian, \#bash, \#shell



--------------------------