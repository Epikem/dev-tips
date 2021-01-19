# -*- coding: utf-8 -*-
#!/usr/bin/python

false = False
true = True
null = None
# import math
TEST = false
try:
    import sys
    for arg in sys.argv:
        if(arg == 'test'):
            print('test mode')
            TEST = True
    pass
except:
    pass


def AddImports(libraryNames):
    for libname in libraryNames:
        if (type(libname) == type(tuple())):
            short = libname[1]
            libname = libname[0]
        else:
            short = None
        try:
            lib = __import__(libname)
        except ImportError:
            pass
        else:
            if short:
                globals()[short] = lib
            else:
                globals()[libname] = lib
    return True


# libnames = ['fileinput', 'codecs', 'operator', 'functools', 'math',
#             'io', 'platform', 'collections', 'mmap', 'logging', 'logging.handlers']
libnames = ['functools', 'math', 'collections']
# libnames = ['math']

AddImports(libnames)
IntellisenseHint = False
if IntellisenseHint:
    import functools
    import math
    import collections
    # import mmap
    # import logging
    # import logging.handlers
    # import defs


# class memoized(object, ):
#     "Decorator. Caches a function's return value each time it is called.\n\tIf called later with the same arguments, the cached value is returned\n\t(not reevaluated).\n\t"

#     def __init__(self, func):
#         self.func = func
#         self.cache = {}

#     def __call__(self, *args):
#         if (not isinstance(args, collections.Hashable)):
#             return self.func(*args)
#         if (args in self.cache):
#             return self.cache[args]
#         else:
#             value = self.func(*args)
#             self.cache[args] = value
#             return value

#         def __repr__(self):
#             "Return the function's docstring."
#             return self.func.__doc__

#         def __get__(self, obj, objtype):
#             'Support instance methods.'
#             return functools.partial(self.__call__, obj)


def it(args, *arg):
    if(TEST):
        print(args, *arg)
    # print(args, vargs)


def floatEqual(a, b):
    diff = math.fabs(a-b)
    if(diff < 1e-10):
        return True
    else:
        return diff <= 1e-8 * max(math.fabs(a), math.fabs(b))

def ria():
    return list(map(int, input().strip(' ').split(' ')))

def ris():
    return list(map(str, input().strip('\n').split(' ')))

def create2dArray(x,y,val=False):
    arr = [val]*y
    for yy in range(y):
        if(x == 0):
            arr[yy] = []
        else: arr[yy] = [val]*x
    return arr

from sys import stdin
input=stdin.readline
import copy
import queue

# from itertools import permutations

q = queue.Queue()
dic = {}
def solve():
    # 원래 하노이와 다른점?
    # 원판의 구별은 없다. 그러나 각 원판을 각 막대로 옮겨야 한다.
    # 재귀적인 구조는 같은 것이다.
    # 움직임의 최소 횟수?
    # 원 하노이에서는 a[n]=2*a[n-1]+1
    # 반대로 생각해볼까? 정렬된 상태에서 주어진 모양으로 만들기 위한 최소 횟수는?
    # 그냥 생각하기엔, A부터 시작해서 1막대에서 A만 남을 때까지 다른 불순물을 3막대로 옮기고, 
    # 2막대에 있는 모든 A를 1로, B나 C를 3으로 옮기고 나면 A는 정리 완료
    # 그 다음, B에 남은 것중 C가 없을 때까지 1로 옮기고
    # C에 있는 것중 B를 2로, C를 A로 전부 옮긴다. B 정리 완료
    # 마지막으로 A에 있는 모든 C를 3으로 옮기면 끝.
    # 그렇지만 이렇게 푼다면 지저분할거 같다.

    # 예제를 보면서 생각하는데 역시 여전히 구멍이 있다. 
    # 1에서 A만 남을때까지 다른 불순물을 3막대로 옮기라고 했지만 이렇게 하게 되면
    # 예제 3을 최적으로 풀 수 없다.
    # 위의 과정들에서, 이미 정리가 되있거나 빈 막대들이 있다면 그걸 먼저 활용해야 한다.

    # 일단 정의부터가 원 하노이와 다르다.
    # 단독 a[n]으로 정의되지 않음
    # a[n]을 막대 1의 위쪽으로부터 n개를 정리하는데 드는 최소 횟수라면,
    # 위쪽으로부터 n+1번째 막대가 a라면 a[n+1]=a[n]일 것이다.
    # 하지만 실제론 배치에 따라 맞는 막대라도 빼줘야 할 때가 있다.

    # 원판이 최대 1~10개라면 그냥 모든 상태를 저장하면서 브루트 포스를 해도 될 듯도 하다.
    # 문제는 상태 탐색을 어떻게 구현하고, 중복 탐색을 어떻게 피하느냐다.
    # 한 상태의 인접 상태는 각 막대에서 다른 막대로 옮기는 6가지 이동이 있다.
    # 이걸 이용하여 bfs로 탐색해나가면 될 듯 하다. 어쩌면 중복 탐색도 필요 없을수도?
    # 그럼 이제 state를 어떻게 정의할까.
    # 게다가 이렇게 state를 쓰게 되면 참조 넘김에 대해서도 주의해야할거 같은데.
    # 현재 문제는, visited를 쓰니 dfs는 되는데 bfs가 아니라서 최적값이 안 나온다.
    # bfs로 탐색하려면 큐를 써야 하는데, 
    # 이 상태를 어떻게 큐로 저장하지? 뭔가 클래스를 사용한다거나 하는
    # 깔끔한 방법이 있을거 같기도 하지만, 잘 모르겠다.
    # 그냥 https://stackoverflow.com/questions/2541865/copying-nested-lists-in-python
    # 여길 참조하여 copy.deepcopy 함수를 써보자.

    # 큐를 써서 bfs로 하려면, 거리에 해당하는 기준이 필요하며, 여기서는 count가 된다.
    # 그러면 bfs는 count를 늘려가며 검색만 하면 된다.
    # 문제는 나는 처음에 count와 state를 따로 분리해서 변수로 두었는데, 그렇게 하면
    # key를 state로 두었을 때 여전히 바로 리턴하는 것이 아니라
    # 같은 key여도 count가 더 나아졌는지 일일히 확인해야 해서 코드가 복잡해진다.
    # 따라서 아예 탐색에 필요한 모든 정보를 한 state에 담는것이 낫다.

    def checkSolved(state):
        solved = True
        alen = len(state['A'])
        blen=len(state['B'])
        clen=len(state['C'])
        for i in range(alen):
            if(state['A'][i] != 'A'):
                solved=False
        for i in range(blen):
            if(state['B'][i] != 'B'): solved=False
        for i in range(clen):
            if(state['C'][i] != 'C'): solved=False
        return solved

    def search(state):


        pass

    def moveOne(state, a,b):
        # move one from top of a to top of b
        if(len(state[a])==0):
            return None
        nextState = copy.deepcopy(state)
        nextState[b].append(nextState[a][-1])
        nextState[a].pop()
        nextState['count']+=1
        return nextState

    a,st=[0,'']
    initialState={}
    lastState={'A':[],'B':[],'C':[], 'count':0}
    colmap = ['A','B','C']
    counts={'A':0,'B':0,'C':0}
    for i in range(3):
        ins = ris()
        a,st=ins if len(ins)==2 else [0,'']
        a,st=int(a),str(st)
        st = list(st)
        for s in st:
            counts[s]+=1
            lastState[s].append(s)
        initialState[colmap[i]]=st
    # it(counts)
    # it('initialState',initialState)
    
    # it('lastState',lastState)
    initialState['count']=0
    # it('initialState',initialState)
    
    q.put(initialState)
    cost = 9999999999
    cnt=0
    rq = queue.Queue()
    rq.put(lastState)
    rdic={}
    while(not q.empty() or not rq.empty()):
        n = q.get()
        if(n is None): continue
        key = str(n['A'])+str(n['B'])+str(n['C'])
        if(key in dic.keys()):
            # cnt+=1
            # it('cnt',cnt)
            # it(n['count'])
            continue
        else:
            # it('new record', len(dic.keys()), n['count'])
            dic[key] = n['count']
        
        # it('n',n)
        
        if(checkSolved(n)):
            cost = n['count']
            break
        if(key in rdic.keys()):
            it('bidirectional search success')
            
            cost = n['count']+rdic[key]
            break
        q.put(moveOne(n, 'A', 'B'))
        q.put(moveOne(n, 'A', 'C'))
        q.put(moveOne(n, 'B', 'A'))
        q.put(moveOne(n, 'B', 'C'))
        q.put(moveOne(n, 'C', 'A'))
        q.put(moveOne(n, 'C', 'B'))

        rn = rq.get()
        if(rn is None): continue
        rkey = str(rn['A'])+str(rn['B'])+str(rn['C'])
        if(rkey in rdic.keys()):
            continue
        else:
            rdic[rkey]=rn['count']
        
        # if(key in dic.keys()):
        #     cost = rn['count']+dic[key]
        #     break
        
        rq.put(moveOne(rn, 'A', 'B'))
        rq.put(moveOne(rn, 'A', 'C'))
        rq.put(moveOne(rn, 'B', 'A'))
        rq.put(moveOne(rn, 'B', 'C'))
        rq.put(moveOne(rn, 'C', 'A'))
        rq.put(moveOne(rn, 'C', 'B'))
    
        # if(cnt%100==0):
        #     it('cnt',cnt, n['count'], rn['count'], key)
        #     it(key in rdic.keys())
        # cnt+=1


    print(cost)
    
    pass

solve()