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

bars = [0]*3
visited = {}
costs = {}
dic = {} # key-state들을매치 저장.
q = queue.SimpleQueue()
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

    def checkSolved(state):
        solved = True
        for i in range(len(state[0])):
            if(state[0][i] != 'A'):
                solved=False
        for i in range(len(state[1])):
            if(state[1][i] != 'B'): solved=False
        for i in range(len(state[2])):
            if(state[2][i] != 'C'): solved=False
        return solved

    def search(state, count):
        key = str(state)
        if(key in visited.keys()):
            if(count < costs[key]):
                costs[key] = count
            return costs[key]
        #     return min(count,costs[key])
        if(count>100): return 999999
        if(checkSolved(state)): 
            # costs[key]=count
            if(key in costs.keys()):
                if(costs[key]<count):
                    return costs[key]
                else:
                    costs[key]=count
            return count
        it(state, count, state[0], len(state[0]))
        visited[key] = True
        cost = 9999999999
        costs[key] = cost
        dic[str(key)]=copy.deepcopy(state)
        # q.put(key)
        if(len(state[0])>0):
            # it(state)
            # it(state[2])
            tmp = state[0].pop()
            state[1].append(tmp)
            nextkey=str(state)
            dic[nextkey]=copy.deepcopy(state)
            q.put(nextkey)
            # cost = min(cost, search(state, count+1))
            tmp = state[1].pop()
            state[2].append(tmp)
            # cost = min(cost, search(state, count+1))
            nextkey=str(state)
            dic[nextkey]=copy.deepcopy(state)
            q.put(nextkey)
            tmp = state[2].pop()
            state[0].append(tmp)

        if(len(state[1])>0):
            tmp = state[1].pop()
            state[0].append(tmp)
            # cost = min(cost, search(state, count+1))
            nextkey=str(state)
            dic[nextkey]=copy.deepcopy(state)
            q.put(nextkey)
            tmp = state[0].pop()
            state[2].append(tmp)
            # cost = min(cost, search(state, count+1))
            nextkey=str(state)
            dic[nextkey]=copy.deepcopy(state)
            q.put(nextkey)
            tmp = state[2].pop()
            state[1].append(tmp)

        if(len(state[2])>0):
            tmp = state[2].pop()
            state[0].append(tmp)
            # cost = min(cost, search(state, count+1))
            nextkey=str(state)
            dic[nextkey]=copy.deepcopy(state)
            q.put(nextkey)
            tmp = state[0].pop()
            state[1].append(tmp)
            # cost = min(cost, search(state, count+1))
            nextkey=str(state)
            dic[nextkey]=copy.deepcopy(state)
            q.put(nextkey)
            tmp = state[1].pop()
            state[2].append(tmp)

        costs[key] = cost


        return cost

    initialState =create2dArray(0,3)
    for i in range(3):
        a,st = ris()
        a = int(a)
        st = list(st)
        it(st)
        for j in range(len(st)):
            initialState[i].append(st[j])
    it(initialState)
    cost=9999999
    nextkey=str(initialState)
    dic[nextkey]=copy.deepcopy(initialState)
    q.put(nextkey)
    while(not q.empty()):
        pick = q.get()
        nextstate = dic[pick]
        # it(type(nextstate))
        cost = min(cost, search(nextstate, 0))
        # costs[key] = cost
    # ans = search(initialState, 0)
    print(cost)
    pass

solve()