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
2. plain counterpart에 비해, 34 res-net은 top-1 에러가 3.5% 낮았다. 매우 깊은 시스템에서 

## tags
- \#study, \#paper, \#ai, \#vision

--------------------------


 