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

def rsa():
    return list(map(str, input().strip('\n').split(' ')))

def create2DArray(rows,cols,val=False):
    return [[val for c in range(cols)] for r in range(rows)]

def create3DArray(zs,ys,xs,val=False):
    return [[[val for x in range(xs)] for y in range(ys)] for z in range(zs)]

def print2DArray(array):
    for r in range(len(array)):
        it(*array[r])

from sys import stdin
input=stdin.readline
import copy
# import queue
from collections import deque

# from itertools import permutations
sys.setrecursionlimit(1000)

def solve():
    # 크기:
    # n*n 즉 2500인데, 거기에 거울의 상태들이 곱해지면 상당히 커진다.
    # 거울의 상태를 어떻게 나타낼 것인가가 문제다.
    # 거울의 최소 개수이므로 bfs로 탐색해 나가는 것이 좋을 텐데,
    # 거울 설치 수는 상태가 구별되지 않는다.
    # 거울은 \방향 또는 /방향이 가능한데, 그걸 조합하면 2^거울수 가 되고,
    # 그러면 조합이 너무 커질거 같은데??
    # 인접 거울 리스트를 만들어 관리한다면?
    # 거울 상태가 \일때의 거울 리스트 및 /일때의 거울 리스트를 만들어 관리하면?
    # 문제는 \일때에도 빛이 어디에서 들어오느냐에 따라 달라진다.
    # 거울의 방향+빛이 오는 방향에 따라 닿게되는 지점이 달라지는데..
    # 인접 거울 리스트를 써도 2500정도에 거울이 빽빽하게 있고, 그 조합을 다 검사한다면 시간초과가 날 것이다.
    # 그러면 두 문에서 도달 가능한지만 알면 되므로 한 문에서 시작해서,
    # 거울을 1개 써서 도달 가능한 공간들, 2개 써서 도달 가능한 공간들 이런 식으로 관리한다면 좋을 것 같다.
    # 문제는 거울 1개도 어느 거울을 쓰느냐에 따라 달라지므로 결국 조합이 커질 수는 있지만,
    # 아마 시간초과될 정도로 거울을 많이 써야 하는 경우는 주어지지 않을 것 같다.
    # 문제는 거울 k개를 쓰는 조합을 어떻게 나타낼 것인가 이다.
    # 방식:
    # bfs로, 다음 배열들을 관리한다
    # foundMirrors[usedMirrorCount] -> 거울 usedMirrorCount개를 써서 찾아진 새 거울들(반대편 문이 나오면 즉시 종료)의 번호.
    # mirror[mirrorNo] -> mirrorNo번째 거울 위치 반환
    # 
    # 문제는 거울의 조합인 mirrorCombination을 어떻게 나타낼 것인가.
    # 비트마스크를 써서?
    # 
    # 문제:
    # 1. 어떻게 조합을 나타내고 순회할 것인가.
    # 2. 어떻게 거울 설치 상태를 적용할 것인가(맵 직접 수정하려면 문자열 수정이 안되므로 int로 변환 거쳐야 함.) 
    # 3. 거울 설치 조합 때마다 문에서 도달 가능한곳을 찾는 식으로 해도 시간초과 안될까?
    # 중요한 것은, 거울이 많이 붙어있을 때, 스킵이 가능해야 할 거 같다는 점이다.
    # 근데 그렇게 되면 bfs가 아니게 된다..
    # 만약 그냥 꺾는 지점의 수만 센다면 훨씬 간단한 bfs가 될거 같은데,
    # 거울의 양면성을 활용해야 하게 된다면 거울의 설치 방향도 고려해야 하므로 훨씬 어려워진다.
    # 그런데, 거울의 양면성을 활용하게 되는 경우가 생길 수 있나?
    # 거울의 양면을 쓴다는 말은, 한쪽으로 왔다가 결국 반대쪽으로 나가는건데, 그럼 결국 그 거울을 쓰지 않는 것과 같다. 따라서 양면 거울이 필요한 경우는 없을거 같다는 생각이 드는데, 벽이 어떻게 조합되느냐에 따라 아닐수도...
    # 일단 꺾는 횟수가 기준이 되는게 맞을거 같은게, 조합이라고 생각하면 최대 2^2500수준이므로 말이 안 된다.
    # 거울이 많을 경우를 대비해 메모이제이션이 필요할거 같기도 한데, 
    # 각 위치의 거울에 대해, 각 진행방향에 대해 최소 카운트로 도달한 횟수를 저장해놓는다면.. 아니다. bfs라면 그냥 돌리면서 카운트 +1하면 된다. bfs이므로 갱신이 일어날 일은 없다.
    # 그러려면, 먼저 현재 진행방향에 대해서는 다 찾고 그다음 꺾을 때 +1씩을 하면 된다.
    # 구현:
    # 1. 큐에 문에서 출발하는 빛 상태 저장.
    # 탐색 시작,
    # . 발견시 패스.
    # 거울 발견시 이미 방문한 거울이면 무시.
    # 아니면 방문했다고 표시하고, (거울 번호, 빛 진행방향, 거울 위치)를 새 큐에 저장
    # 벽에 닿을 때까지 진행.
    # 새 큐를 이용해 돌리되, 카운트 +1을 한다.
    # 이렇게 하게 되면, 각 저장된 위치에서 빛 진행 방향들을 기준 수직 위치들을 시도해보아야 한다.
    # 그리고, 문에서 출발할 때는 수직 방향으로만 가야 하지만, 
    # 거울에서 꺾을 때는 좌우가 다 가능하고, 큐에서 다음 라운드 돌릴 때는 거울을 꺼내므로 저장된 방향의 수직
    # 방향들로 가야 한다. 즉 한 거울 꺾을 때 두가지 방향 다 시도해야 하는데,
    # 그건 더 쉽게 말하면 그냥 그 거울이 위치한 곳에 빛 방향의 수직인 모든 라인을 다 검사한다는 뜻이다.
    # 다만 벽에는 막혀야 함. 위에서 거울 번호가 아니라 타일 타입(문,거울,등)을 표시해야 할 듯.

    # 예제 때문에 벽에 둘러싸고 벽에 문이 있는 형태일 줄 알았다. 그런데 한 80%에서 틀렸다.
    # 역시 글로 나오지 않은 조건은 조건이 아니라고 생각해야 한다.
    # 그렇다면 문에서 가능한 방향 모두를 시도해보아야 하나??

    n = ria()[0]
    mapstr=[0]*n
    mapper={'*':1,'.':0,'!':2,'#':3}
    graph=create2DArray(n,n,0)
    # visited=create2DArray(n,n,False)
    visited=create3DArray(4,n,n,False)
    dirToNum={True:0,False:1}
    doors=[]
    for i in range(n):
        mapline=rsa()[0]
        arr=list(mapline)
        graph[i]=[]
        for j in range(n):
            if(arr[j]=='#'):
                doors.append((i,j))
            graph[i].append(mapper[arr[j]])
    # print2DArray(graph)
    # it(doors)
    
    count=0
    q=deque()
    startDoor=doors.pop()
    def getDoorDirection(pos):
        (y,x)=pos
        if(y==0):
            return (+1,0)
        elif(y==n-1):
            return (-1,0)
        elif(x==0):
            return (0,+1)
        elif(x==n-1):
            return (0,-1)
        else:
            it('ERROR')
            return (0,0)
    def isHorizontalDir(direction):
        if(abs(direction[0])==0):
            return True
        else:
            return False
    def getHorizontalDir():
        return [(0,-1),(0,+1)]
    def getVerticalDir():
        return [(-1,0),(+1,0)]
    startDir=getDoorDirection(startDoor)
    # it('startDoor, startDir',startDoor, startDir)
    q.append((3, startDir, startDoor))
    nq=deque()
    while(True):
        here=q.popleft()
        (no, ldir, mpos)=here
        targetDirs=[]
        (y,x)=mpos
        if(no==3):
            #문. 4방향 모두 시도
            # targetDirs.append(ldir)
            targetDirs=[(+1,0),(-1,0),(0,+1),(0,-1)]
            pass
        elif(no==2):
            if(isHorizontalDir(ldir)):
                targetDirs=getVerticalDir()
            else:
                targetDirs=getHorizontalDir()

        for targetDir in targetDirs:
            # it(targetDir, targetDir)
            # it(y,x,y+targetDir[0],x+targetDir[1])
            # y,x=y+targetDir[0],x+targetDir[1]
            (y,x)=mpos
            curitem=graph[y][x]
            while(curitem!=mapper['*']):
                y,x=y+targetDir[0],x+targetDir[1]
                if(y<0 or y>=n or x<0 or x>=n):
                    break
                curitem=graph[y][x]
                isHorizontal=isHorizontalDir(targetDir)
                if(visited[dirToNum[isHorizontal]][y][x]):
                    # it('passing targetDir,y,x',targetDir,y,x)
                    
                    continue
                # it('searching',curitem, y, x)
                visited[dirToNum[isHorizontal]][y][x]=True
                if(curitem==mapper['.']):
                    continue
                elif(curitem==mapper['!']):
                    # it('FOUND!',y,x)
                    nq.append((mapper['!'], targetDir, (y,x)))
                elif(curitem==mapper['#']):
                    if(startDoor[0]!=y or startDoor[1]!=x):
                        print(count)
                        return
                pass
            pass
        if(len(q)==0):
            if(len(nq)==0):
                it('ERROR')
                # break
            q=nq
            nq=deque()
            count+=1
        pass


    pass

solve()
# import profile
# profile.run("solve()")