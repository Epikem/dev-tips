# visual-studio-code-setting-for-c-and-cpp-debugging

Visual Studio Code에서 C/C++ 프로그래밍( Windows / Ubuntu)

---

[TOC]

## desc

- 이 팁은 [이 블로그 포스트](https://webnautes.tistory.com/1158)의 축약임.

준비물

- c/c++ 컴파일러 (윈도우면 MinGW)
- vscode
- c/c++ 프로젝트 폴더, 파일
- vscode c/c++ extension

블로그에서 1~4에 해당. 이미 vscode를 쓰고 있고 c/c++을 시도해 봤다면 있을법 함. 근데 그 이후 설정은 도대체 어떻게 알아내는건지 모르겠다.

## inst

- instruction
  1. 코드 컴파일 및 실행
  2. 한글 입출력 예제
  3. MinGW만 사용시 문법 자동 완성 설정(IntelliSense)
  4. 디버깅하는 방법
  5. F5로 바로 빌드 및 디버깅 하게 하기. (내가 추가)

1. 코드 컴파일 및 실행
   1. vscode의 메뉴에서 **터미널-기본 빌드 작업 구성** 선택
   2. **템플릿에서 tasks.json 만들기** 선택
   3. **Others** _임의의 외부 명령을 실행하는 예_ 템플릿 선택
   4. tasks.json 파일 내용을 다음과 같이 수정

    > 📂 `tasks.json`
    ```json
    {
      "version": "2.0.0",
      "runner": "terminal",
      "type": "shell",
      "echoCommand": true,
      "presentation": { "reveal": "always" },
      "tasks": [
        //C++ 컴파일
        {
          "label": "save and compile for C++",
          "command": "g++",
          "args": ["${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}"],
          "group": "build",
          //컴파일시 에러를 편집기에 반영
          //참고:   https://code.visualstudio.com/docs/editor/tasks#_defining-a-problem-matcher
          "problemMatcher": {
            "fileLocation": ["relative", "${workspaceRoot}"],
            "pattern": {
              // The regular expression.
              //Example to match: helloWorld.c:5:3: warning: implicit declaration of function 'prinft'
              "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning error):\\s+(.*)$",
              "file": 1,
              "line": 2,
              "column": 3,
              "severity": 4,
              "message": 5
            }
          }
        },
        //C 컴파일
        {
          "label": "save and compile for C",
          "command": "gcc",
          "args": ["${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}"],
          "group": "build",
          //컴파일시 에러를 편집기에 반영
          //참고:   https://code.visualstudio.com/docs/editor/tasks#_defining-a-problem-matcher
          "problemMatcher": {
            "fileLocation": ["relative", "${workspaceRoot}"],
            "pattern": {
              // The regular expression.
              //Example to match: helloWorld.c:5:3: warning: implicit declaration of function 'prinft'
              "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning error):\\s+(.*)$",
              "file": 1,
              "line": 2,
              "column": 3,
              "severity": 4,
              "message": 5
            }
          }
        },
        // // 바이너리 실행(Ubuntu)
        // {
        //     "label": "execute",
        //     "command": "cd ${fileDirname} && ./${fileBasenameNoExtension}",
        //     "group": "test"
        // }
        // 바이너리 실행(Windows)
        {
          "label": "execute",
          "command": "cmd",
          "group": "test",
          "args": ["/C", "${fileDirname}\\${fileBasenameNoExtension}"]
        }
      ]
    }
    ```
    우분투의 경우 주석을 반대로 하면 됨.

   5. tasks.json의 task들에 대한 단축키 바인딩 설정을 위해 `keybindings.json`에 다음 내용 추가

    > 📂 `keybindings.json`
    ```json
    // 키 바인딩을 이 파일에 넣어서 기본값을 덮어씁니다.
    [
      //컴파일
      { "key": "ctrl+alt+c", "command": "workbench.action.tasks.build" },
      
      //실행
      { "key": "ctrl+alt+r", "command": "workbench.action.tasks.test" }
    ]
    ```

    6. 이제 빌드 및 실행이 가능하다.

나의 경우 여기까지 했을 때 코드의 `#include` 부분에 녹색 줄이 뜨고 빌드가 실패했다(코드 2).
이후 포스트의 나머지 부분 보고 따라하니 고쳐짐.


2. 한글 입출력 예제
   1. 리눅스의 경우 패스.
   2. 윈도우의 경우 설정에서 euc-kr로 바꾸라는데, 나의 경우 안 바꿔도 그냥 되는거 같아서 냅둠.
3. MinGW만 사용시 문법 자동 완성 설정(IntelliSense)
   1. 빠른 명령 창(F1)을 열고, `c/cpp: Edit Configurations...`를 선택. `.vscode` 폴더에 `c_cpp_properties.json`파일이 추가된다.
   2. 그 파일의 내용을 아래와 같이 덮어씌운다.

> 📂 `c_cpp_properties.json`
```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceRoot}",
                "C:/MinGW/lib/gcc/mingw32/6.3.0/include/c++",
                "C:/MinGW/lib/gcc/mingw32/6.3.0/include/c++/mingw32",
                "C:/MinGW/lib/gcc/mingw32/6.3.0/include/c++/backward",
                "C:/MinGW/include",
                "C:/MinGW/lib/gcc/mingw32/6.3.0/include-fixed",
                "C:/MinGW/lib/gcc/mingw32/6.3.0/include"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "__GNUC__=6",
                "__cdecl=__attribute__((__cdecl__))"
            ],
            "intelliSenseMode": "clang-x64",
            "browse": {
                "path": [
                    "${workspaceRoot}",
                    "C:/MinGW/lib/gcc/mingw32/6.3.0/include/c++",
                    "C:/MinGW/lib/gcc/mingw32/6.3.0/include/c++/mingw32",
                    "C:/MinGW/lib/gcc/mingw32/6.3.0/include/c++/backward",
                    "C:/MinGW/include",
                    "C:/MinGW/lib/gcc/mingw32/6.3.0/include-fixed",
                    "C:/MinGW/lib/gcc/mingw32/6.3.0/include"
                ],
                "limitSymbolsToIncludedHeaders": true,
                "databaseFilename": ""
            }
        }
    ],
    "version": 4
}
```

4. 디버깅하는 방법
   1. `tasks.json`파일의 컴파일 태스크에 대한 `args`옵션에 아래와 같이 `-g`옵션 추가.

> 📂 `tasks.json`
```json
"tasks":[
  {
    "label":"...",
    "command":"g++",
    "args":[
      "${file}",
      "-g", // 이 라인 추가.
      "-o",
      "..."
    ]
  }
]
```

1. F5로 바로 빌드 및 디버깅 하게 하기.
   1. `launch.json`에서 옵션 중 `preLaunchTask`를 아까 `tasks.json`의 빌드를 하는 task의 `label`로 설정해 주면 f5를 누르면 저장 및 빌드 및 디버깅까지 바로 된다.

놀랍게도 이렇게 하고 보니 visual studio에서 하는 것 보다 더 느리다..

이상하게 노트북에서는 되는데 pc에서는 에러가 난다. `sys/un.h`인가 파일을 찾을 수 없다나 분명히 `main.exe`가 빌드되서 있어야 하는데 그 경로가 없다고 하고 이유가 실행하려는 파일이 중간에 바뀌어서일 수도 있다는데 정확한 원인을 모르겠다. 검색해보니 mingw 64비트용을 설치해야한다는 거 같은데 한 번 해봐야 겠다. 문제는 이미 32비트로 설치해버려서 어떻게 이걸 삭제하는지 모르겠다. 하나씩 mark for removal 해서 지워야만 하는건가?..

다운로드 페이지가 두 가지가 있는데 위에꺼도 64비트도 된다고 하는거 같은데 흠.. 일단 시도해 보자
- https://sourceforge.net/projects/mingw/
- https://sourceforge.net/projects/mingw-w64/

아래 링크걸로 다시 설치하여 해보니 성공함. (설치할 때 x64, 등 설정 해줘야 함.)

그런데 상위 개발 폴더인 dev에서 실행하면 cwd에서 input.txt와 output.txt를 찾지 못한다.
cwd를 현재 실행하는 파일을 포함하는 폴더로 설정하려면 어떻게 해야하지?
`launch.json`에서 옵션 `cwd`를 

```json
  "cwd": "${fileDirname}",
```

이렇게 바꾸니 성공함.

### 단점

너무 느리다. 호버해서 하나라도 배열길이가 긴 배열 등을 봐버리면 버벅대기 시작하면서 더 이상 진행이 안 된다. 그냥 tasks.json 수정해서 컴파일 및 실행 자동화로 출력값 비교해서 하는게 나을 듯.

### 디버깅 없이 직접 실행 스크립트 짜기

1. tasks.json 이용

아래와 같이 `tasks.json`작성하고, 단축키에 `group.kind` 이름으로 연결한다. (`workbench.actions.tasks.<groupName>`)
isDefault옵션을 주면 그 그룹네임을 실행시켰을때 바로 실행하며, 안 주면 그 그룹네임의 task들 중 무엇을 실행할건지 선택해서 실행하게 된다. 조금 실망스러운건 그룹네임이 `build`아니면 `test` 두 가지만 가능한거 같다.

> 📂 `tasks.json`
```json
  {
    "label": "build and execute cpp without debug",
    "command": ".",
    "dependsOn":["build cpp without debug"],
    "group": {
        "kind": "test",
        "isDefault": true
    },
    "options": {
        "cwd": "${fileDirname}"
    },
    "args": [
        "${fileDirname}\\${fileBasenameNoExtension}",
        "TestMode"
    ]
  },
```

2. 파워셸 스크립트 이용

> 📂 `executeCpp.ps1`
```ps1
  Write-Host "Starting $($args).cpp";

  Write-Host "Compiling"  -ForegroundColor Yellow -BackgroundColor DarkGreen;
  g++ ./$args.cpp -o ./$args;
  Write-Host "Running"  -ForegroundColor Yellow -BackgroundColor DarkGreen;
  . ./$args.exe TestMode;
  Write-Host "Done"  -ForegroundColor Yellow -BackgroundColor DarkGreen;
```
이렇게 짜고, vscode에서 다음과 같이 tasks.json에 쓴다.

> 📂 `tasks.json`
```json
  {
    "label": "build and execute cpp without debug using pwsh script",
    "command": "...\\executeCpp.ps1",
    "group": {
        "kind": "test",
        "isDefault": true
    },
    "options": {
        "cwd": "${fileDirname}"
    },
    "args": [
        "${fileBasenameNoExtension}"
    ]
  }
```
물론 이 경우 이전 task는 없애거나 group을 없애줘야 한다. 

> 📂 `keybindings.json`
```json
  {
    "key": "ctrl+r ctrl+r",
    "command": "workbench.action.tasks.test"
  },
```

## dep

## ref

- [tistory blog](https://webnautes.tistory.com/1158)

## tags

#vscode, #setting

---
