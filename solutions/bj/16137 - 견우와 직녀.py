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

    pass


def floatEqual(a, b):
    diff = math.fabs(a-b)
    if(diff < 1e-10):
        return True
    else:
        return diff <= 1e-8 * max(math.fabs(a), math.fabs(b))

def ria():
    return list(map(int, input().strip(' ').split(' ')))

def rsa():
    return list(map(str, input().strip('\n').split(' ')))

# def create2dArray(y,x,val=False):
#     arr = [val]*x
#     for xx in range(x):
#         if(y == 0):
#             arr[xx] = []
#         else: arr[xx] = [val]*y
#     return arr

def create2DArray(rows,cols,val=False):
    return [[val for c in range(cols)] for r in range(rows)]

def create3DArray(zs,ys,xs,val=False):
    return [[[val for x in range(xs)] for y in range(ys)] for z in range(zs)]

def print2DArray(array):
    for r in range(len(array)):
        it(*array[r])

def takeFirst(x):
    return x[0]

def takeSecond(x):
    return x[1]

from sys import stdin
input=stdin.readline
import copy
# import queue
from collections import deque

# from itertools import permutations
sys.setrecursionlimit(10000)

# https://www.acmicpc.net/problem/16137

SIZE=300010
MOD=998244353

def solve():

    # n이 10밖에 안되기 때문에, 칸 수 뿐 아니라 어느 타이밍에 어느 위치에 있는지 모두 저장할 수 있다.
    # 10*10*inf??
    # 그보다는 10*10에 visited 여부가 아니라 그 칸까지 도달하는 최소 값만 저장하면 될거 같다.
    # 문제는 추가 오작교는 단 하나만 설치 가능하다는 점. 그 설치 위치에 따라
    # maps[10][10][10][10]->map[pr][pc][r][c]을 오작교가 pr,pc에 설치되었을 때 r,c에 도달하는데 최소 시간이라고 한다면? 아니면 그냥 10*10 돌면서 오작교 설치가능한지 확인하고 전부 초기화해서 풀어도 될 것이다.
    # 맵이 하도 작기 때문에, 맵을 100번 만들어서 풀어도 충분할 것이다.
    # 근데, 돌면서 오작교를 둘 수 없는 곳은 어떻게 구별하지?
    # 방향벡터를 도는 형태로 만들어서, 각 이전 방향이 또 절벽이었다면 실패해야 할 것이다.
    # 아 생각해보니, 맵이 10*10이지만 탐색은 벽에 의해 그보다 훨씬 길어질 가능성이 크다.
    # 따라서 이렇게 하면 안 된다.
    # 절벽을 구불구불 지나다 가장 최적으로 다리를 둬야 하는 곳에 둬야하는 것이다.
    # 어떻게???
    # 이 공간을 어떻게 탐색할지도 어려운데, 탐색공간 자체가 다리로 달라지니 어떻게 모델링해야할지 감이 안 온다.
    # 그렇다면, 현재 상태에서, 추가오작교를 사용했는지 안했는지에 따라 각 절벽을 만날 때마다 추가 오작교를 사용하는 경우, 사용하지 않는 경우를 계산해서 탐색.
    # 현재 상태에서 추가오작교를 이미 썼다면 그냥 탐색. 근데 이걸 bfs로 안하면 시간초과가 날까??
    # 맵이 구불구불하면 10*10에서 최대 몇 번의 탐색이 필요한가? 100번 정도다.
    # 그러면 그냥 처음 방법대로 해도 될 듯?
    # 그러면, 만약 주기때문에 한 곳을 두번 가야 할 일이 생길 수 있나?
    # 그런 일은 없을 거 같지만, 주기때문에 기다려야 하는 일은 생길 수 있다.
    # 기다린 것을 두번 간다고 생각하면 필요할 수 있다.
    # 기다려야 하는 경우가 있을 수 있으므로 모든 칸에 대해 최소만 저장하는 방법으로는 안 된다.
    # 오작교가 있을 때만 특별 처리해서, 바로 반대 방향으로 기다리는 시간까지 포함해서 큐에 저장한다면?
    # 그러면 bfs가 어긋나게 된다. 하지만 사실 10*10이므로 bfs가 그리 중요하진 않다.
    # 문제는 매개변수든 상태 객체를 쓰든 상태를 어떻게 표현하느냐다.
    # 오작교를 넘었더니 주기가 길어서 돌아서 가는 길이 더 빠를수도 있다. bfs로는 구현이 어렵고
    # dfs로는 제대로 visited를 구현하지 않으면 폭발이 발생한다.
    # 
    n,p=ria()
    maps=create2DArray(n,n,0)
    for r in range(n):
        maps[r]=ria()

    dy=[-1,0,+1,0,-1]
    dx=[0,-1,0,+1,0]
    costs=create3DArray(2,n,n,999999)

    def dfs(time, used, r, c):
        if(r<0 or r>=n or c<0 or c>=n):
            return 99999999
        costs[used][r][c]=min(costs[used][r][c], time)
        
        for i in range(4):
            nr,nc=r+dy[i],c+dx[i]
            if(nr<0 or nr>=n or nc<0 or nc>=n):
                continue
            if(costs[used][nr][nc]<=time):
                continue
            if(maps[nr][nc]==1):
                costs[used][nr][nc]=time+1
                dfs(time+1,used,nr,nc)
            elif(maps[nr][nc]==0):
                if(used):
                    continue
                if(maps[r][c]>=2 or maps[r][c]==0):
                    # 연속해서 건너기 불가.
                    continue
                putable=True
                for j in range(4):
                    nnr,nnc=nr+dy[j],nc+dx[j]
                    nnnr,nnnc=nr+dy[j+1],nc+dx[j+1]
                    if(nnr<0 or nnr>=n or nnc<0 or nnc>=n):
                        continue
                    if(nnnr<0 or nnnr>=n or nnnc<0 or nnnc>=n):
                        continue
                    if(maps[nnr][nnc]==maps[nnnr][nnnc] and maps[nnr][nnc]==0):
                        putable=False
                        break
                if(not putable):
                    continue
                remainTime=p-time%p
                costs[used][nr][nc]=time+remainTime
                dfs(time+remainTime,True,nr,nc)
                pass
            elif(maps[nr][nc]>=2):
                # 주기 다리가 있다.
                if(maps[r][c]>=2 or maps[r][c]==0):
                    # 연속해서 건너기 불가.
                    continue
                period = maps[nr][nc]
                remainTime=period-time%period
                if(costs[used][nr][nc]<=time+remainTime):
                    continue
                dfs(time+remainTime,used,nr,nc)
                costs[used][nr][nc]=time+remainTime
                
                
        pass

    dfs(0,False,0,0)
    # print2DArray(costs[False])
    # print2DArray(costs[True])
    print(min(costs[False][n-1][n-1],costs[True][n-1][n-1]))
    pass

solve()
# import profile
# profile.run("solve()")