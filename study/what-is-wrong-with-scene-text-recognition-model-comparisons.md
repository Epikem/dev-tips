# what-is-wrong-with-scene-text-recognition-model-comparisons

논문공부 WIP

--------------------------

## Abstract:

세 가지 기여로 기존 STR의 공정한 비교가 어렵던 점을 해결:
  1. training, evaluation 데이터셋의 불일치 및 그에 따른 성능 영향 조사
  2. 대부분의 모델에 적용 가능한 통합된 4단계 STR framework 도입.
  3. 모듈별 속도,정확성,메모리 사용량에 대한 성능 평가를 분석? 어떤 '모듈'을 의미하는거지? -> 기존 STR 모듈들?

## 1. intro

신경망을 통해 STR문제를 해결하려는 여러 시도가 있었음.

'face value'? 

IC13 데이터셋의 일부를 써서 벤치마크한 모듈들이 15%이상의 측정오차를 가질 수 있음.

이러한 문제를 다음 기여로 해결:
1. 기존 많이 사용되는 데이터셋을 분석함. 그 결과 IC03에서 7개의 샘플이 빠져있고 IC13에서 158개의 샘플이 빠져있음을 알아냄.

2. 통합 STR framework를 만듬:
  str 모델을 네 가지 연속된 수행으로 분리:
    1. transformation
    2. feature extraction
    3. sequence modelling
    4. prediction
  ?? 이 프레임워크는 기존 방법 뿐 아니라 모듈별 기여에 대한 포괄적 분석에 대한 변형도 제공함?

3. 일관된 실험환경에서 모듈별 기여를 정확성,속도,메모리 사용량 면에서 측정

STR의 남은 도전과제를 확인하기 위해 실패 케이스를 분석?

## 2. STR에서 Dataset의 중요성



### 2.1 합성된 데이터셋

- MJSynth : 8.9M개의 단어박스 이미지.
- SynthText : 5.5M

어떤 선행연구의 성능개선이 모델 자체의 발전인지 데이터가 많아서인지 알기 어렵다.

실험 4.2에서 훈련 데이터셋이 최종 벤치마크 결과에 주는 영향을 나타냄.

### 2.2 평가를 위한 실제 데이터셋

다른 서브셋들이 모델 평가에 쓰여 일관된 비교를 방해.

- 정규 데이터(regular): 가로로 방향으로 글자 사이에 공간이 있는 데이터셋

  - IIIT
  - SVT
  - IC03
  - IC13

- 비정규 데이터(irregular): 변형된 텍스트

  - IC15
  - SP
  - CT

## 3. STR 프레임워크 분석

기존 모델들을 분석하여 공통점을 도출함. 네 단계의 순차 작업을 한다는 것을 발견함:

  1. Transformation : STN 네트워크로 입력 이미지를 평탄화
  2. Feature extraction : 입력 이미지를 글자 인식에 유리한 형태로 바꿈. 글꼴,색상,크기,배경들 의미없는 정보를 줄임
  3. Sequence modeling : 각 글자를 더 견고하게 예측하기 위해 문맥 정보를 판단함.
  4. Prediction : 입력 feature로부터 문자열을 예측함.

### 3.1 Transformation stage

?'fidual points'를 활용하는 STN의 변형인 TPS 기술로 입력 이미지를 normalize함.

제안된 프레임워크는 TPS를 쓰거나 뺄 수 있음.

### 3.2 Feature extraction stage

이 단계에서 CNN이 입력 이미지를 시각적 feature map으로 변환함.

$$V=\{v_i\}, i=1,...,I$$

I는 feature map의 열의 개수.

?? CNN은 보통 이미지 전체에 대해 하나의 결과를 내놓지 않나?
열의 개수가 있다는 것은 이미지의 각 열 1px에 대해 CNN을 돌린다는건가? 아니면 글자 단위로 잘라서 돌린다는 걸까?

? 'receptive field'?

다음 구조들을 연구함: VGG, RCNN, ResNet 즉 세가지 옵션

### 3.3 Sequence modeling stage

feature map의 각 열이 sequence의 프레임으로서 쓰임. 문맥 정보를 활용하기 위해 양방향 LSTM을 사용하기도 함. H=Seq(V)

계산 복잡성을 줄이기 위해 쓰지 않기도 함.

제공된 프레임워크에서는 옵션임.

### 3.4 Prediction stage

input H로부터 문자열을 예측함. 두가지 방법:
  1. connectionist temporal classification(CTC) 뭔뜻? 
  feature와 예측 문자열 길이가 달라도 됨.
   The key methods for CTC are to predict a character at each column (hi ∈ H) and to modify the full character sequence into a non-ﬁxed stream of characters by deleting repeated characters and blanks

 ???
  2. attention based sequence prediction(Attn):
  예측을 위해 자동으로 입력 정보로부터 정보 흐름을 캡쳐함. ? STR 모델이 출력 클래스 종속을 나타내는 글자 단위 언어 모델을 배우게 함???  It enables an STRmodeltolearnacharacter-levellanguagemodelrepresenting output class dependencies. 

## 4. Experiment and Analysis

위 각 네 단계에서 2x3x2x2가지 옵션=24가지 경우를 모두 실험해봄.


### 4.1 구현 상세 -> 실질적 비교들이 나옴.

공정 비교를 위해 데이터셋을 fix함.

**STR training and model selection** 
MJSynth 8.9M과 SynthText 5.5M을 합친 것을 훈련데이터로 씀.
decay rate p=0.95로 설정한 AdaDelta optimizer를 사용. 배치 사이즈 192, 반복 횟수 30만번. ? Gradient clipping 크기 5 사용.
? 모든 파라미터는 He 방법으로 초기화됨.

검증 세트로 IC13, IC15, IIIT, SVT를 합친 것을 사용. 2000스텝마다 검증함.

**Evaluation metrics**
정확성, 시간, 메모리 측면에서 성능을 측정
- 정확성: 여러 real-world 데이터셋을 합친 것을 사용. 영문자와 숫자만 평가. 각 STR 조합에 대해 5번의 다른 랜덤 시드를 사용하여 정확도를 평균함. 속도 평가에서는 이미지당 평균 clock time을 밀리초로 측정. 메모리 평가에서는 전체 STR 파이프라인에서 학습 가능한 소수 파라미터의 개수를 셈.

**Environment** 252GB RAM..


### 4.2 Analysis on training datasets

다른 환경에서 학습한 모델들의 성능을 비교하기 어렵다.

MJS와 ST를 같이 써서 학습한 것이 따로 쓴 것보다 더 성능이 좋다.
따라서 학습 데이터의 다양성이 개수보다 중요하다.

### 4.3 Analysis of trade-offs for module combinations

accuracy-speed 와 accuracy-memory 트레이드오프

fig 5에 따르면 CTC가 attn보다 빠르고, RCNN VGG ResNet 순으로 메모리 사용량이 커진다.

### 4.4 Module analysis

베이스 옵션에 대해 다른 옵션들의 영향 조사.


- [ ] prediction이 정확히 어떻게 CNN 구조를 적용시켜 돌아가는건지? 열이 어떻게 정해지는지 등.
- [ ] Gradient clipping
- [ ] He's method
- [ ] receptive field
- [ ] AdaDelta 특징
- [ ] face value 단어 뜻



## 5. 결론

 일관된 환경으로 STR 모듈간 비교를 해보았다.

 To achieve this goal, we have introducedacommonframeworkamongkeySTRmethods, as well as consistent datasets: seven benchmark evaluation datasets and two training datasets (MJ and ST). 


자연어 처리에서 입력 문장의 종류를 분석하여 정보처리를 할 필요가..

## tags
- \#study, \#paper, \#ai, \#vision

--------------------------


 