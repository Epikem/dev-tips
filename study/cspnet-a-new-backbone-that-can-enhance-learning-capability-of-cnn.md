# cspnet-a-new-backbone-that-can-enhance-learning-capability-of-cnn

논문공부 WIP

https://arxiv.org/pdf/1911.11929.pdf

--------------------------

## Abstract:

## 1. introduction

더 넓고 깊어짐에 따라 신경망neural network이 더 강력한 것으로 알려졌다. 그러나, 신경망 구조를 늘리는 것은 계산량 또한 늘리게 된다. 실세계 활용에서 작은 기기에서 추론 시간을 줄여야 하므로 경량 컴퓨팅이 점차 관심을 얻고 있고 이는 컴퓨터 비전 알고리즘 분야의 큰 도전과제가 되었다. 비록 모바일 CPU만을 위해 고안된 접근법이 있기도 하지만, *그들이* 채택한 depth-wise separable convolution 기술은 ASIC과 같은 엣지 컴퓨팅 시스템을 위한 산업 IC 설계에 호환되지 않는다. 이 논문에서 우리는 ResNet, ResNeXt, DenseNet과 같은 최신 접근법의 계산량을 조사했다. 성능을 희생하지 않고 CPU와 모바일 GPU에서 언급된 신경망들을 돌릴 수 있는 계산 효율적인 컴포넌트들을 개발했다.

이 연구에서, 우리는 Cross Stage Partial Network를 소개한다. CSPNet 설계의 메인 목적은 계산량을 줄이면서도 풍부한 그래디언트 조합을 얻는 것이다. 이 목표는 베이스 층의 피쳐 맵을 두 부분으로 나눈 다음 다시 제안된 cross-stage 계층을 통해 합침으로써 달성되었다. 우리의 메인 컨셉은 그래디언트 흐름을 쪼개어 네트워크의 여러 경로로 전파되도록 하는 것입니다. **In this way, we have confirmed that the propagated gradient information can have a large correlation difference by switching concatenation and transition steps** concatenation switching과 transition 스텝들을 통해 전파된 그래디언트 정보가 큰 correlation difference를 가짐을 확인했다. 추가적으로, Fig1에 나타난 대로 CSPNet은 계산량을 크게 줄이고, 추론 시간과 정확도 모두를 향상시킬 수 있다. 제안된 CSPNet기반 물체인식기는 다음 세 가지 문제를 다룬다:

1. CNN의 학습능력 강화

기존 CNN의 정확도는 lightweightening시 매우 감퇴된다. 그래서  lightweightening후에도 충분한 정확도를 유지할 수 있도록 CNN의 학습 능력을 강화하려 했다. CSPNet 구조는 쉽게 ResNet, ResNeXt, DenseNet 등에 적용될 수 있다. CSPNet을 위 언급된 구조들에 적용한 결과 계산량computation effort이 10~20%정도 감소한데다, ImageNet 이미지 분류 정확도 측면에서 ResNet, ResNext, DenseNet, ...등 의 성능을 능가했다.  

2. 계산 병목구조 제거

계산 병목구조는 추론 과정의 사이클 수를 늘리거나 일부 계산 유닛들을 쉬게 할 수 있다. 그러므로 CNN의 각 층에 계산량을 고루 분포하여 각 계산 유닛을 효율적으로 사용하여 불필요한 에너지 사용을 줄이도록 했다. CSPNet은 PeleeNet의 계산 병목을 반으로 줄이는 성과를 보인다. 게다가, MS COCO 데이터셋 기반 물체 인식 실험에서, 제안된 모델은 YOLO-v3 모델에 대해 테스트한 결과 80%의 계산 병목을 줄였다.

3. 메모리 비용 절감

동적 랜덤 접근 메모리 (DRAM)의 웨이퍼 제작 비용은 매우 비싸고, 큰 공간을 차지한다. 만약 효과적으로 메모리 비용을 줄일 수 있다면 ASIC 제작 비용을 매우 크게 줄일 수 있다. 게다가, 작은 웨이퍼는 다양한 엣지 컴퓨팅 기기에서 쓰일 수 있다. 메모리 사용량을 줄이기 위해 cross-channel 풀링[6]을 이용하여 피쳐 피라미드 생성 과정에서 피쳐 맵을 압축했다. 이리하여 제안된 CSPNet과 물체 인식기는 PeleeNet에서 피쳐 피라미드를 생성하는데 드는 메모리 사용량을 75%까지 줄일 수 있었다.

CSPNet은 CNN의 학습 능력capability을 향상시킬 수 있기에 더 작은 모델로 더 나은 정확도를 얻을 수 있도록 한다. 제안된 모델은 GTX 1080ti에서 109fps로 50% COCO AP_50 성능을 달성했다. CSPNet이 효과적으로 메모리 사용을 상당히 절약 가능하므로, 제공된 방법으로 Intel Core i9-9900K에서 52fps로 40% COCO AP_50의 성능을 달성했다. 추가적으로, CSPNet은 계산 병목을 상당히 줄일 수 있고, Exact Fusion Model(EFM)이 효과적으로 요구 메모리 사용량을 줄일 수 있어 Nvidia Jetson TX2에서 49 fps로 42% COCO AP_50을 달성했다.

- [ ] [DenseNet](https://hoya012.github.io/blog/DenseNet-Tutorial-1/)
- [ ] PeleeNet
- [ ] Exact Fusion Model
- [x] [cross-channel pooling](https://light-tree.tistory.com/147)
- [ ] CSPNet 네트워크 구조
- [ ] depthwise-separable convolution


## 2. Related Work

## 3. Method

- [ ] 두 부분으로 나누어 하는 것이 어떻게 기울기 중복을 줄이나?
- [ ] Fig 2의 그림은 한 레이어에 대한 것인가? 아니면 전체 네트워크 형태인가?
- [ ] 

네트워크 구조 참조 : https://github.com/WongKinYiu/CrossStagePartialNetworks/blob/master/in%20progress/darknet/icfg/darknet53-leaky.cfg


cnn 기본 용어 상세 설명 : http://taewan.kim/post/cnn/



## tags
- \#study, \#paper, \#ai, \#vision

--------------------------


 