## 악취 종류

### 기이한 이름
- 함수 선언 바꾸기
- 변수 이름 바꾸기
- 필드 이름 바꾸기

### 중복 코드
- 함수 추출하기
- 문장 슬라이드하기
  - 코드가 비슷한데 완전 똑같지는 않은 경우 슬라이드 후 추출 가능한지 확인
- 메서드 올리기
  - 파생 서브클래스들에 중복된 경우

### 긴 함수
- 함수 추출하기
  - 99%
  - switch-case에서 각 case도 추출
- 임시 변수를 질의 함수로 바꾸기
  - 추출된 함수의 임시 변수 수 줄이기
- 매개변수 객체 만들기
  - 매개변수 수 줄이기
- 객체 통째로 넘기기
  - 매개변수 수 줄이기
- 함수를 명령으로 만들기
  - 위 리팩토링을 적용해도 너무 변수/매개변수가 많을 경우 (큰 변경)
- 조건문 분해하기
  - 조건문이 많은 경우
- 조건부 로직을 다형성으로 바꾸기
  - 같은 조건 기준으로 나뉘는 switch문이 여러개인 경우?
- 반복문 쪼개기
  - 반복문 포함해서 추출하기 적절한 이름이 떠오르지 않는다면 두 가지 이상 작업이 섞여있을 수 있음

### 긴 매개변수 목록
- 매개변수를 질의 함수로 바꾸기
  - 다른 매개변수에서 값을 얻어올 수 있는 경우
- 객체 통째로 넘기기
  - 사용중인 데이터 구조에서 각각 뽑아서 매개변수로 넘기고 있는 경우
- 매개변수 객체 만들기
  - 항상 같이 전달되는 매개변수들을 같이 묶기
- 플래그 인수 제거하기
  - 함수의 동작 방식을 정하는 매개변수의 경우
- 여러 함수를 클래스로 묶기
  - 여러 개의 함수가 특정 매개변수의 값을 공통으로 사용할 때 클래스로 만들어서 클래스의 필드로 정의
  - 함수형 프로그래밍에서의 '부분 적용 함수 (partially applied function)'을 생성하는것과 같은 것

### 전역 데이터
전역 변수/싱글톤 모두 비슷. 변경되지 않는 전역 데이터는 그나마 나음
- 변수 캡슐화하기
  - 다른 코드에서 오염시킬 가능성이 있는 데이터의 경우
  - 추가적으로 접근자 함수들을 클래스나 모듈에 집어넣어 한정시킬 수 있음


### 가변 데이터
무분별한 데이터 수정에 따른 위험을 줄이는 방법
- 변수 캡슐화하기
  - 정해진 함수를 이용해서만 변경 가능
- 변수 쪼개기
  - 하나의 변수에 용도가 다른 값들을 저장하고 관리하는 경우
  - 용도별로 독립 변수에 저장
- 문장 슬라이드하기
- 함수 추출하기
  - 갱신 로직을 다른 코드로부터 분리하기
- 질의 함수와 변경 함수 분리하기
  - API를 만드는 경우
- 세터 제거하기
- 파생 변수를 질의 함수로 바꾸기
  - 값을 다른 곳에서 설정할 수 있는 가변 데이터
- 여러 함수를 클래스로 묶기
- 여러 함수를 변환 함수로 묶기
  - 변수 갱신 코드의 유효범위 제한
- 참조를 값으로 바꾸기
  - 구조체처럼 내부 필드에 데이터를 담는 변수
  - 내부 필드를 직접 수정하지 않고 구조체를 직접 바꾸기

### 뒤엉킨 변경
구조가 얽혀서 하나를 바꾸거나 추가할 때 여러 곳을 건드려야 하게 되는 경우
- 단계 쪼개기
  - 순차적 로직의 경우, db 접근 -> 비즈니스 로직 처리
- 함수 옮기기
  - 각 처리 과정에서 각기 다른 맥락의 함수들을 호출하는 빈도가 높은 경우
- 함수 추출하기
  - 여러 맥락의 일에 관여하는 함수가 있는 경우
- 클래스 추출하기
  - 모듈이 클래스인 경우

### 산탄총 수술
하나를 변경하려는데 잘게 여러개를 건드려야 하는 경우
변경해야할 부분이 코드 전반에 퍼져있어 놓치기 쉬워짐
- 함수 옮기기
- 필드 옮기기
  - 함께 변경되는 대상들을 모듈에 모아두기
- 여러 함수들을 클래스로 묶기
  - 비슷한 데이터를 다루는 함수가 많은 경우
- 여러 함수를 변환 함수로 묶기
  - 데이터 구조를 변환/보강하는 함수들의 경우
- 단계 쪼개기
  - 묶은 함수들의 출력 결과를 묶어 다음 단계 로직으로 전달할 수 있는 경우
- 함수 인라인하기
- 클래스 인라인하기
  - 어설프게 분리된 로직의 경우 인라인해서 다루기 쉽게 만들기

### 기능 편애
자기가 속한 모듈과의 상호작용보다 다른 모듈과의 함수/데이터 상호작용이 많은 경우
- 함수 옮기기
- 함수 추출하기
  - 함수의 일부에서만 외부 의존이 큰 경우
  - 의존 모듈이 다양한 경우

전략 패턴, 방문자 패턴, 켄트 벡의 자기 위임 등도 뒤엉킨 변경을 제거할 때 사용.
함께 변경할 대상을 한 데 모으는 것.

### 데이터 뭉치
- 클래스 추출하기
  - 필드 형태의 데이터 뭉치
- 매개변수 객체 만들기
- 객체 통째로 넘기기
  - 메서드 시그니처에 있는 매개변수 데이터 뭉치들에 대해 적용
  - 값 하나를 삭제했을 때 나머지 데이터로 의미가 없다면 객체가 되길 갈망하는 데이터임

여기서 만든 클래스로 옮길 함수도 생각해보면 좋다.

### 기본형 집착
전화번호: 사용자에게 보여줄 때에 일관적 형식으로 표시하는 기능 등이 필요
이러한 정보를 단순 문자열로 다루기엔 부족하다.
- 기본형을 객체로 바꾸기
  - 문명 사회로 데이터를 옮겨주기
- 타입 코드를 서브클래스로 바꾸기
- 조건부 로직을 다형성으로 바꾸기
  - 기본형으로 표현된 코드가 조건부 동작을 제어하는 타입 코드로 쓰인 경우, 위 두개를 차례로 적용
- 클래스 추출하기
- 매개변수 객체 만들기
  - 같이 어울리는 데이터 뭉치

### 반복되는 switch문


### 반복문

- 반복문을 파이프라인으로 바꾸기

### 성의 없는 요소

### 추측성 일반화

### 임시 필드

### 메시지 체인

- 위임 숨기기
- 함수 추출하기
- 함수 옮기기

### 중개자

- 중개자 제거하기
- 함수 인라인하기

### 내부자 거래

- 함수 옮기기
- 필드 옮기기
- 위임 숨기기
- 서브클래스를 위임으로 바꾸기
- 슈퍼클래스를 위임으로 바꾸기

### 거대한 클래스


### 서로 다른 인터페이스의 대안 클래스들


### 데이터 클래스


### 상속 포기

### 주석



