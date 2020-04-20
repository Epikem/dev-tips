# very-deep-convolutional-networks-for-large-scale-image-recognition

논문공부 - vgg

wip

--------------------------

## 0. Abstract:

작은 conv filter와 깊은 망으로 뛰어난 성능 획득 가능.

## 1. introduction

- convnet이 비전부분에서 흥함
- convnet의 깊이와 성능의 관계를 고찰. 작은 conv filter를 써서 다른부분을 고정하고 깊이를 계속 늘림
- 그랬더니 결과가 좋았다.

- s2에서 convnet 구성을 설명.
- 이미지 분류 및 평가가 sec3에서 제공됨.
- 구성들이 ILSVRC 데이터셋에 대해 sec4에서 비교됨.
- s5에 결론.

## 2. ConvNet configs

- 이전 구조와 비슷하게 구성하여 비교가능하게 함.
- 2.1에서 이 논문의 convnet의 일반적 구성을 기술
- 2.2에서 평가에 사용된 구체적 구성 서술
- 2.3에서 이전 기술들과 비교

### 2.1 architecture

- 입력 이미지: 

### 4.3 MULTI-CROP EVALUATION

테이블 5에서 밀집 convNet 평가와 multi-crop 평가를 비교함. 두 기법의 소프트맥스 출력을 평균하여 상보성도 평가함.
그 결과, multi-crop이 dense방법보다 약간 나았다. 또, 그 두 기법을 조합한 결과가 더 나았으므로 상호보완적이다.
이 결과는 convolution boundary 조건에 대한 다른 처리가 원인인 것으로 추측된다.


### 4.4 CONVNET FUSION

지금까지는, 개별 ConvNet 모델의 성능을 평가했다. 이번에는 여러 모델의 소프트맥스 클래스 posterior들을 평균하여 출력을 병합해보았다.
모델들이 서로 상호보완적이므로 이 방법은 성능 향상을 가져왔고, ILSVRC top 제출에 쓰였다.

submissions in 2012 (Krizhevsky et al., 2012) and 2013 (Zeiler & Fergus, 2013; Sermanet et al.,
2014).

ILSVRC 제출을 할 때에는 단일 스케일 신경망과 다중 스케일 모델 D (완전 연결층만 튜닝하여)만 학습된 상태였다. 7개 신경망의 앙상블은 7.3%에러를 가졌고, 제출 후 두 개의 최고 성능 다중 스케일 모델로 테스트한 결과 dense evaluation의 에러가 7.0%, combined dense and multi-crop 평가에 대한 에러가 6.8%였다. 참고로, 우리의 최고 단일 모델을 7.1% 에러율을 기록했다 (model E, table 5).

- [ ] posterior?
- [ ] 구체적으로 어떻게 다중 스케일 모델이 학습되는가??
- [ ] dense evaluation vs multi-crop, 무엇을 나타내는가? -> 섹션 3.2 참고
참고해도 잘 모르겠어서, 리뷰 블로그 참고함. 리뷰 블로그 참고해도 잘 모르겠음..

multi-crop은 그냥 이미지를 스케일 후 여러 위치에서 샘플링(잘라내기) 했다는 거 같은데, dense evaluation의 경우 무엇인지..

### 4.5 COMPARISON WITH THE STATE OF THE ART

마지막으로, 우리의 최신 결과를 Table 7에 나타내었다. ILSVRC-2014 분류 대회에서 "VGG"팀은 7개 모델의 앙상블로 7.3% 테스트 에러를 기록하여 2등을 했다. 제출 후,
2개 모델의 조합으로 6.8% 에러를 기록했다.

Table7에서 볼 수 있듯, 우리의 심층 convNet 모델은 기존 세대의 모델을 압도한다.
우리의 결과는 또한 분류 대회의 우승자와도 경쟁할 만 하다. (GoogLeNet은 6.7% 에러를 기록)

우리의 최고 성능 모델이 겨우 두 모델을 합친 것을 고려하면 이 결과는 상당히 고무적이다 (ILSVRC 경쟁 모델들에 비교하면 훨씬 적다.)
단일 신경망 성능으로 비교하자면, 단일 GoogLeNet을 0.9% 차이로 우리의 모델이 최고 성능을 가진다. (7.0% test error).
특히, 우리는 LeCun의 고전 ConvNet 모델을 깊이를 매우 깊게 하여 개선시켰다.


## ref
- https://arxiv.org/pdf/1409.1556.pdf
- [라온피플-OverFeat](https://blog.naver.com/PostView.nhn?blogId=laonple&logNo=220752877630&parentCategoryNo=&categoryNo=22&viewDate=&isShowPopularPosts=false&from=postView)
- [라온피플-VGG](https://m.blog.naver.com/PostView.nhn?blogId=laonple&logNo=220749876381&proxyReferer=https:%2F%2Fwww.google.com%2F)

## tags
- \#study, \#paper, \#ai, \#vision

--------------------------
