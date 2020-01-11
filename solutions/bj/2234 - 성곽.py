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

def create2dArray(x,y,val=False):
    arr = [val]*y
    for yy in range(y):
        arr[yy] = [val]*x
    return arr

from sys import stdin
input=stdin.readline
# from itertools import permutations

roomof = {} # [index]번 칸이 속하는 방 번호를 나타낸다.
sizeofroom={} # [index]번 부모가 속하는 방의 크기
maps = []
visited = [False]*55
roots = []

def solve():
    # 서 북 동 남 1 2 4 8
    # 1. 방의 개수
    # 2. 가장 넓은 방의 넓이
    # 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
    
    # 다른건 어떻게 구현으로 세어도 3번은 꽤 어려워 보인다.
    # 전부 다 시도할 만 한가? 시간제한은 2초.
    # m,n<=50 이므로 칸은 최대 2500, 벽은 최대 2500*4=10000개이므로 사실상 시도할 만 하다.
    # 그렇지만 벽의 제거가 O(m*n)이므로 벽의 제거로 방을 효율적으로 합칠 수 있어야(O(1))할 것이다.

    # 여기서 효율적이어야 하는 연산은, 방 합치기, 특정 칸의 방이 몇번 방인지 구별하기이다.
    # 각 방의 넓이를 구하는 것은 구별만 된다면 m*n비용으로 해도 상관없을 듯.
    # 유니온 파인드? 구조를 쓰면 좋을 듯 한데 어떻게 구현하는지 까먹었다.
    # 그냥 딕셔너리로 하면 구별은 되지만 방 합치기가 좀 문제다.
    # 탐색을 하려면 벽을 없앴다가 취소하는걸 반복해야 하는데. 없애서 합치는걸 구현해도 방을 다시 나누는건 어려워 보인다. 이전 자료를 기억해놨다가 취소하게 구현해야 한다.
    # 딕셔너리로 한다면 어떻게? 벽이 없는 칸에 대해 더이상 부모가 나오지 않을 때까지 인덱싱하여 부모를 찾아감.
    # 마지막 부모를 현재 칸의 부모로 저장하면서, 그 부모에 해당하는 크기+1
    # 각 부모들에 대해 그 방의 칸의 크기를 저장해 놓는다면, 벽들을 순회하면서
    # 벽을 사이에 둔 두 방의 크기의 합이 가장 큰 경우가 벽을 없앴을 때 최대 크기가 된다.

    # 잘 안되네. 부모를 찾아가게 했지만 초기화 순서때문에 키에러가 난다.
    # 그리고 다 초기화 후에 부모를 등록하게 하면 각자 자기를 부모로 이미 등록한 후라
    # 제대로 등록이 안 된다. 재귀적으로 등록하게 해야 했을 듯.

    # 재귀적으로 찾게 하려니 재귀제한에 걸려버린다. visited이런걸로 관리해야할거 같은데,
    # 결국 dfs/bfs다.

        
    n,m=ria()

    visited = create2dArray(n,m)
    # maps = create2dArray(n,m)
    for i in range(m):
        maps.append(ria())
    def search(x,y, root):
        
        here = (y,x)
        if(x<0 or x>=n or y<0 or y>=m):
            return -1
        if(visited[y][x]):
            return roomof[(y,x)]
        # it(f'x, y, visited: {x} {y} {visited[y][x]}')
        visited[y][x]=True
        roomof[(y,x)] = root
        sizeofroom[root]+=1
        if(not maps[y][x] & 1):
            search(x-1,y, root)
        if(not maps[y][x] & 2):
            search(x,y-1, root)
        if(not maps[y][x] & 4):
            search(x+1,y, root)
        if(not maps[y][x] & 8):
            search(x,y+1, root)
        return root

    def getSizeOfPoint(x,y):
        if(x<0 or x>=n or y<0 or y>=m):
            return -1
        return sizeofroom[roomof[(y,x)]]

    def getRoomOf(x,y):
        if(x<0 or x>=n or y<0 or y>=m):
            return None
        return roomof[(y,x)]
    def searchPair(x,y):
        
        if(x<0 or x>=n or y<0 or y>=m):
            return -1
        sizeofhere = sizeofroom[roomof[(y,x)]]
        maxv = 0
        if(maps[y][x] & 1 and getRoomOf(x,y) != getRoomOf(x-1,y)):
            maxv = max(maxv, getSizeOfPoint(x-1,y))
            # if(maxv+sizeofhere==18): it(f'l x y {x} {y}')
        if(maps[y][x] & 2 and getRoomOf(x,y) != getRoomOf(x,y-1)):
            maxv = max(maxv, getSizeOfPoint(x,y-1))
            # if(maxv+sizeofhere==18): it(f'u x y {x} {y}')
        if(maps[y][x] & 4 and getRoomOf(x,y) != getRoomOf(x+1,y)):
            maxv = max(maxv, getSizeOfPoint(x+1,y))
            # if(maxv+sizeofhere==18): it(f'r x y {x} {y}')
        if(maps[y][x] & 8 and getRoomOf(x,y) != getRoomOf(x,y+1)):
            maxv = max(maxv, getSizeOfPoint(x,y+1))
            # if(maxv+sizeofhere==18): it(f'd x y {x} {y}')
        # if(maxv+sizeofhere==18):it(f'x,y {x} {y} sizeofhere {sizeofhere}')
        return maxv + sizeofhere

    for y in range(m):
        for x in range(n):
            sizeofroom[(y,x)] = 0
            
    # it(maps)
    for y in range(m):
        for x in range(n):
            if(not visited[y][x]):
                roots.append((y,x))
            search(x,y, (y,x))

    maxvv=0
    for y in range(m):
        for x in range(n):
            v= searchPair(x,y)
            if(v>maxvv):
                maxvv = v

    # it(roomof)

    # it(sizeofroom)
    
    # it(roots)
    maxroomsize = 0
    for root in roots:
        # it(sizeofroom[root])
        maxroomsize = sizeofroom[root] if sizeofroom[root] > maxroomsize else maxroomsize

    print(len(roots))
    print(maxroomsize)
    print(maxvv)
    pass

solve()