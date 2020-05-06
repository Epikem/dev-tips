# deep-residual-learning-for-image-recognition

논문공부 WIP

--------------------------

## Abstract:
깊은 모델은 학습하기 어려움.
We explicitly reformulate the layers as learn-ing residual functions with reference to the layer inputs, in-stead of learning unreferenced functions. 포괄적 경험적 증거로 이 residual 네트워크가 상당히 깊어져도 학습하기 좋은 것다는 것을 보일 것이다. VGG보다 8배 깊은 152층 네트워크로 ILSVRC 2015 대회에서 승리함.The depth of representations is of central importance for many visual recognition tasks. 표현의 깊이가 여러 시각 인식 과제에서 상당히 중요하다. 

## 1. Introduction

이미지 분류 과제에 깊은 합성공 신경망이 혁신을 가져왔다. Deep networks naturally integrate low/mid/high-level features [49] and classifiers in an end-to-end multi-layer fashion, and the “levels” of features can be enriched by the number of stacked layers (depth). 심층 망은 자연스럽게? 여러 단계의 특징과 분류기를 다층 방식으로 통합시킨다. 단계별 특징들은 깊게 쌓인 층들에 의해 enrich될 수 있다. 최근 조사들에서도 네트워크 깊이의 중요성이 드러난다.

깊이의 중요성으로부터, 한 가지 질문이 떠오른다: Is learning better networks as easy as stacking more layers? (더 나은 네트워크를 학습하는 것이 더 많은 층을 쌓는 것만큼 쉬운가?) 
악명높은 기울기 소실 문제가 이 질문에 대한 걸림돌이 되어왔다. 기울기 소실은 수렴을 hamper한다. (which hamper convergence from the beginning. : 네트워크의 (시간상)시작부터의 수렴을 방해한다는 것인가, 아니면 시작 부분의 수렴을 방해한다는 것인가??) . 그러나 이 문제는 정규화된 초기화 기법과 중간 normalization 층들의 도입으로 상당 부분 해결되었다. 

깊은 망이 수렴하기 시작할 때, degradation 문제가 발견되었다: 깊이가 증가함에 따라 정확도가 포화되고, 빠르게 감소하는 현상. 의외로, 이 현상은 과적합에 의한 것이 아니어서, suitably 깊은 모델에 층을 더 더하면 train 에러가 더 증가한다. 이것은 [10,41]에서 보고되었고 우리의 실험에서 완전히 확인되었다.
그림 1이 전형적인 예를 보여준다.

(train 정확도의)퇴화는 모든 시스템이 비슷하게 최적화하기 쉽지는 않다는 것을 보여준다. 얕은 구조와 거기에 층을 더한 깊은 counterpart에 대해 생각해보자. 학습된 얕은 층에 항등 매핑을 하는 층을 더하면 깊은 층 solution이 된다. 이는 더 깊은 모델이 더 얕은 모델보다 더 높은 train 에러를 produce해선 안 된다는 뜻이다. 그러나 우리의 현재 solver로 시행된 실험에서는 construct된 해답보다 더 나은 해답을 찾지 못함을 보여준다(어색). 

deep residual learning 프레임워크의 도입으로 이 문제를 해결한다.Instead of hoping each few stacked layers directly fit a desired underlying mapping, we explicitly let these layers fit a residual mapping??. 각 층이 목표된 매핑을 직접적으로 학습시키기를 기대하는 대신, explicitly 이러한 층들이 residual 매핑을 학습시키도록 했다. 엄밀히, desired underlying 매핑을 $H(x)$라 하면, 쌓인 비선형 층들이 또다른 매핑 $F(x):=H(x)-x$를 학습하도록 했다. 기존의 매핑은 $F(x)+x$로 recast 된다. 기존의 참조되지 않은 매핑을 학습시키는 것보다, residual 매핑을 학습시키는 것이 쉬울 것이라고 가정한다.  To the extreme, if an identity mapping were optimal, it would be easier to push the residual to zero than to fit an identity mapping by a stack of nonlinear layers. 

$F(x)+x$의 formulation은 지름길 연결로 이루어진 feedforward 신경망으로 구현될 수 있다. 
...
항등 단축 연결은 계산 복잡도나 매개변수 수에 영향을 주지 않는다.
...

...

(대충 기존 방법보다 낫다는 내용)

- [ ] naturally
- [ ] suitably
- [ ] normalization 번역
- [ ] hamper
- [ ] Is learning better networks as easy as stacking more layers? 번역
- [ ] recast
- [ ] desired underlying mapping
- [ ] explicitly

## 2. Related Work

**Residual Representations** 
(이해안됨)
In image recognition, VLAD[18] is a representation that encodes by the residual vectors with respect to a dictionary, and Fisher Vector [30] can be formulated as a probabilistic version [18] of VLAD. Both of them are powerful shallow representations for image retrieval and classification [4, 47]. For vector quantization, encoding residual vectors [17] is shown to be more effective than encoding original vectors. 

residual 표현이 공학적으로 효율적이라는 듯.

In low-level vision and computer graphics, for solving Partial Differential Equations (PDEs), the widely used Multigrid method [3] reformulates the system as subproblems at multiple scales, where each subproblem is responsible for the residual solution between a coarser and a finer scale. An alternative to Multigrid is hierarchical basis preconditioning [44, 45], which relies on variables that represent residual vectors between two scales. It has been shown[3, 44, 45] that these solvers converge much faster than standard solvers that are unaware of the residual nature of the solutions. These methods suggest that a good reformulation or preconditioning can simplify the optimization.

- [ ] VLAD?
- [ ] residual vector

**Shortcut Connections**
이에 대해 여러 시도와 연구가 있었음. 





## 3. Deep Residual Learning

### 3.1 Residual Learning

신경망 $H(x)$에 대해 $H(x)$가 임의의 함수를 근사할 수 있다면, 그 자체를 원하는 함수로 두는 게 아니라 $F(x)=H(x)-x$로 두어 $H(x)$가 $F(x)+x$를 학습하게 하는 것. 둘 다 목표 함수를 근사 가능해야 하지만, 학습 난이도는 다를 수 있다.

이 reformulation은 전술된 비직관적 퇴화 문제로부터 영감을 받음.
 ...
최적화기가 여러 비선형 층을 학습할 때 항등 매핑을 근사하는데 어려움이 있을 수 있음을 시사한다. 
...
만약 항등 매핑이 최적이라면, 비선형 층의 가중치를 0으로 만들어 항등 매핑을 근사할 것이다.

If the optimal function is closer to an identitymapping than to a zero mapping, it should be easier for thesolver to find the perturbations with reference to an identitymapping, than to learn the function as a new one.




- [ ] asymptotically
- [ ] precondition
- [ ] perturbations


### 3.2 Identity Mapping by Shortcuts

$$y=F(x,\{W_i\})+x$$

...

x와 F의 차원이 같아야 함. 그렇지 않으면 차원을 맞추기 위해 단축 연결을 이용하여 선형 사상 $W_s$을 수행할 수 있음.

...

F가 1층이면 이득이 없었음.

element-wise 덧셈으로 CNN에도 적용 가능. 

### 3.3 Network Architectures

**Plain Network**
VGG Net에 기반한 plain 망을 구성.(비교군?)

**Residual Network** 
위의 plain 망에 기반하여 단축 연결을 삽입함.

### 3.4 Inplementation

...


## 4. Experiments

### 4.1 ImageNet Classification

1000 클래스를 가진 이미지넷 2012 데이터셋으로 평가함. 모델은 128만개의 이미지로 학습되었고, 5만개의 검증 이미지로 평가됨. 10만개의 시험 이미지로 최종 평가를 함. top-1, top-5 두 가지 에러율을 측정함.

**Plain Networks** 
먼저 18,34층 plain층을 평가함. 표2에 의하면 더 깊은 34층 plain 망이 더 얕은 망보다 더 높은 validation 에러를 가짐. 그 이유를 밝히기 위해 그림 4에서 학습중의 학습/검증 에러를 비교함. 여기서 퇴화 문제를 발견함 - 34층 망의 해공간이 18층 망의 해공간을 포함함에도 전체 학습에서 train에러가 높음.

이러한 최적화의 어려움은 기울기 소실과는 무관할 것 같다. 이 plain 망들은 순전파된 신호들의 분산이 0이 아님을 보장하는 BN으로 학습되었기 때문이다. BN을 써서 역전파된 기울기들이 적절한healthy norms를 가지는 것 또한 확인했다. 사실은, 34넷은 여전히 competetive한 정확도를 가질 수 있고, 이는 solver가 어느정도 작동함을 말한다. 깊은 plain망은 지수적으로 낮은 수렴 속도를 가져서 학습 에러가 높은 거 아닌가 싶다. 그러한 최적화의 어려움은 나중에 연구해보겠다.

**Residual Networks**
단축 연결이 각 3x3 필터에 추가된 것 말고는 똑같은 18,34망을 평가함. 증가하는 차원들에 대해 모든 단축 연결에 항등 매핑과 제로 패딩을 써서 plain counterparts에 대해 추가적인 파라미터가 없도록 했다.

표2와 그림4에서 세 가지 주요 특징을 관찰했다.

1. residual learning에서 상황이 뒤집혔다. (34가 18보다 좋음, 검증 데이터에 대해서도)
이것은 이 세팅에서 퇴화 문제가 잘 해결되었고 증가된 깊이로부터 정확도 상승을 얻는데 성공했음을 나타낸다.
2. plain counterpart에 비해, 34 res-net은 top-1 에러가 3.5% 낮았다. 이는 매우 깊은 시스템에서 residual learning의 효과성을 입증한다.

마지막으로, 18층 일반/residual 넷이 상당히 정확한데, resNet버전의 수렴이 더 빠르다. 층이 너무 깊지 않으면 일반 넷에서도 학습 결과가 괜찮다. 그렇지만 ResNet을 쓰면 *초기 단계에 빠른 수렴을 가능하게 하여(구체적으로 어떻게?)* 최적화를 쉽게 만든다.

**Identity vs. Projection Shortcuts** 

매개변수 없는 항등 매핑이 학습을 돕는다는 것을 보였고, 다음으로 projection shortcuts를 조사함. Table 3에서 세 가지 옵션을 비교함. 
- A. 차원을 늘리기 위해 제로 패딩 shortcut을 사용. 모든 숏컷에 매개변수 없음.
- B. 차원을 늘리기 위해 projection shortcut을 사용. 다른 숏컷은 identity
- C. 모든 숏컷이 projection

테이블 3은 모든 세 가지 옵션이 일반 넷에 비해 상당히 나음을 보여준다.
B가 A보다 약간 나은데, A에서 제로패딩된 차원이 실제로는 residual learning을 가지지 않기 때문이라고 추측한다. C는 B보다 marginally 나은데,많은 (13) projection shortcut들에 의한 추가적인 매개변수의 영향이라고 생각한다. 그러나 A/B/C간의 차이가 작다는 것은 퇴화 문제를 해결하는 데 projection shortcut들이 필수적이지 않음을 말한다. 그래서 메모리/시간 복잡도와 모델 사이즈를 줄이기 위해 논문의 나머지 부분에선 option C를 쓰지 않았다. 아래에 소개된 병목 구조의 복잡도를 증가하지 않으므로 항등 숏컷은 특별히 중요하다.

**Deeper Bottleneck Architectures** 
다음으로 ImageNet을 위한 더 깊은 넷을 서술한다. 현실적인 학습 시간을 위해 빌딩 블록을 *bottlenet* design으로 수정하였다. 각각의 residual function F에 대해 2층이 아닌 3층 스택을 사용하였다(fig 5). 세 층은 1x1, 3x3, 1x1 conv들이다. 1x1 층들은 차원을 줄이고 다시 늘리는(복원) 역할을 하고, 3x3층을 더 작은 입력/출력 차원에 대해 병목이 되도록 한다??
앞서 언급한 대로 identity shortcut은 시간 복잡도와 모델 크기를 줄이는 데 중요하다. 만약 숏컷을 projection으로 바꾸면 시간 복잡도와 모델 사이즈가 두 배가 된다. 

- [ ] marginally


**50-layer ResNet**
34층 넷의 각 2층마다 3층으로 바꾸어 50층 ResNet으로 만듬. 차원 증가를 위해 옵션 b를 사용. 3.8 bil FLOPS.

**101층, 152층 ResNet**
더 많은 3층 블록을 추가(표 1)하여 101층과 152층 ResNet을 만듬. 깊이가 엄청 깊어졌는데도 152층 ResNet이 VGG16/19넷보다 낮은 복잡도를 보임. 50/101/152층 ResNet들은 34층 ResNet보다 상당히 정확함(표 3,4). degradation problem이 생기지 않음을 관찰했고 그래서 깊어진 만큼 성능 향상을 보임. 

**Comparisons with State-of-the-art Methods**
표 4에서 이전 최고 단일 모델 결과와 비교함.
베이스라인 34-ResNet은 매우 근접한 정확도를 보임. 152층 ResNet은 단일 모델 top-5 검증 에서 4.49%를 기록함. 이것은 이전의 모든 앙상블 모델을 능가함. 다른 깊이의 여섯 모델의 앙상블(제출시 152층짜리는 두개)을 테스트한 결과 top-5 에러 3.57%를 기록하여 ILSVRC 2015에서 1위를 함.

### 4.2 CIFAR-10과 분석

5만개 학습 이미지와 1만개 테스트 이미지를 가진 CIFAR-10 데이터셋에 대해 연구함. 최신 기록 갱신 목적이 아닌 깊은 망이 어떻게 학습되는지 알아보기 위해 의도적으로 간단한 구조를 사용함.

Fig3에 일반/잔차 구조가 기술됨. 입력은 평균으로 뺄셈된 32x32이미지. 1층은 3x3 conv. 그 후 3x3 conv로 각각 (32,16,8) 피쳐 맵을 가지는 6n층 사용. 각 feature map 사이즈에 대해 2n층. 필터 개수는 각각 (16,32,64)개임.

크기 2로 서브샘플링함.

총 6n+2개의 가중치 있는 층으로 구성됨.

예측:
1층이 3x3 conv이면 

- [ ] 구체적 구성이 어떻게 되는 거지??? cnn 구조, 필터, 채널, 피쳐 맵, 차원 상관관계.
- [ ] feature map size,
- [ ] number of filters
- [ ] subsampling

~실제 구성 방식 서술~

plain 대상과 비교하여 층의 깊이도, 폭도, 파라미터 개수도 같음.

가중치 decay 0.0001, 모멘텀 0.9, [13]의 가중치 초기화, BN 사용. 드롭아웃은 쓰지 않음.
미니배치 사이즈 128로 두 개의 GPU로 학습함. 
학습 속도 0.1로 시작하여 32k, 48k에서 10배씩 줄임. 64k에서 학습 정지.

학습을 위해 데이터 증가를 [24]에 나온 방식을 사용. 4 픽셀을 각 사이드에 패딩함. 가로반전/무반전 이미지에서 32x32 crop으로 추출. 테스트를 위해서는 본래 이미지만 사용.

We further explore n = 18 that leads to a 110-layer
ResNet. In this case, we find that the initial learning rate
of 0.1 is slightly too large to start converging5
. So we use
0.01 to warm up the training until the training error is below
80% (about 400 iterations), and then go back to 0.1 and continue training. The rest of the learning schedule is as done
previously. This 110-layer network converges well (Fig. 6,
middle). It has fewer parameters than other deep and thin

결론: ImageNet에서와 마찬가지로 ResNet의 망이 깊을 때 성능이 더 좋음.


https://datascienceschool.net/view-notebook/958022040c544257aa7ba88643d6c032/

**Analysis of Layer Responses**
깊이에 따른 망 값의 표준 편차를 계산함. 깊을 수록 0에 가깝게 나옴.
층이 많을 수록 개별 층이 신호를 덜 수정한다?

**exploring over 1000 layers**
n=200 즉 1202층 네트워크를 학습한 결과 최적화에서 어려움을 보이진 않았다: 학습 에러가 매우 작음.
그러나 110층짜리 네트워크보다 높은 에러를 보임. 이는 오버피팅의 영향으로 보임. 작은 데이터셋에 비해 너무 크기 때문인 것으로 추측함.
정규화를 하면 나아질 수 있으나 비교가 목적이므로 이 논문에서는 하지 않음.

### 4.3 Object Detection on PASCAL and MS COCO

다른 데이터셋들에 대해서도 잘 작동함(좋은 일반화 성능).

물체 인식에서의 적용. FASTER-R-CNN 을 감지기 구현으로 유지하고 VGG-16을 ResNet으로 대체한 결과 성능이 향상됨.




- [ ] FLOPs? 어떻게 계산되나.


## tags
- \#study, \#paper, \#ai, \#vision

--------------------------


 