# yolov4-optimal-speed-and-accuracy-of-object-detection

논문공부 WIP

--------------------------

## Abstract:

cnn 정확성 향상을 위한 feature들 중에는 일반적으로 적용되는 것과 그렇지 않은 것이 있는데, 다음과 같은 feature들이 일반적이라고 추정함:

Weighted-Residual-Connections  (WRC),Cross-Stage-Partial-connections  (CSP),  Cross  mini-BatchNormalization   (CmBN),   Self-adversarial-training   (SAT)and  Mish-activation.   We  use  new  features:   WRC,  CSP,CmBN, SAT, Mish activation,  Mosaic data augmentation,CmBN, DropBlock regularization, and CIoU loss
이런 feature들을 조합하여 최신 결과를 얻어냄.

## 1. Introduction

속도-정확성-GPU성능 간 트레이드오프가 필요하다.

1개의 일반 GPU만으로 돌릴만한 CNN을 설계했다. 이 논문에서의 새로운 공헌은 다음과 같다:

1. We develope an efficient and powerful object detection model. It makes everyone can use a 1080 Ti or 2080 Ti GPU to train a super fast and accurate object detector.
2. We  verify  the  influence  of  state-of-the-art  Bag-of-Freebies and Bag-of-Specials methods of object detec-tion during the detector training.
3. We  modify  state-of-the-art  methods  and  make  themmore  effecient  and  suitable  for  single  GPU  training,including CBN [89], PAN [49], SAM [85], etc.

- [ ] WRC, CSP, CmBN, SAT, Mish-activation, Mosaic data augmentation, DropBlock regularization, CIoU loss
- [ ] CBN, PAN, SAM
- [ ] Bag-of-freebies, Bag-of-Specials



## 3.4 구성

In this section, we shall elaborate the details of YOLOv4.

YOLOv4 consists of:
- Backbone: CSPDarknet53
- Neck: SPP, PAN
- Head: YOLOv3

YOLOv4 uses:
- Bag of Freebies for backbone: CutMix & Mosaic data augmentation, DropBlock regularization, Class label smoothing
- Bag of Specials: Mish activation, Cross-stage partial connections(CSP), Multi input weighted residual connections (MiWRC)
- Bag of Freebies for detector: CIoU-loss, CmBN, DropBlock regularization, Mosaic data augmentation, Self-Adversarial Training, Eliminate grid sensitivity, Using multiple anchors for a single ground truth, Cosine annealing scheduler, Optimal hyperparameters, Random training shapes
- Bag of Specials for detector: Mish activation, SPP-block, SAM-block, PAN path-aggregation block, DIoU-NMS


## 5. 결과

그림 8에 다른 최신 object detector와의 비교가 있음. yolov4는 Pareto optimality curve에 위치해 있고 최신 탐지기보다 속도와 정확성 모든 면에서 나음.

GPU에 따라 성능이 다르게 나오기도 하므로 YOLOv4를 Maxwell, Pascal, Volta아키텍쳐에서도 돌려봄. 표8이 Maxwell GPU를 사용한 결과와 다른 모델과의 비교. 

## 6. 결론

다른 모든 탐지기보다 더 빠르고 더 정확한 최신의 탐지기를 제공함.
8-16GB VRAM을 가진 일반 GPU로 학습되고 사용될 수 있음.
? The original concept of one-stage anchor-based detectors has proven its viability.
기존 앵커 기반 단일 스테이지 탐지기 모델이 그 효과성을 입증했다?

분류기와 검출기의 정확도를 높이기 위해 다양한 feature들을 테스트하여 선별했다.
이러한 feature들이 향후 연구와 개발에서 best-practice로 이용될 수 있다.

## 7. 감사

저자는 glenn jocher께 mosaic data augmentation 아이디어 제공, 유전 알고리즘으로 하이퍼 파라미터 튜닝 및 grid sensitivity 문제 해결에 감사한다.





## tags
- \#study, \#paper, \#ai, \#vision

--------------------------


 