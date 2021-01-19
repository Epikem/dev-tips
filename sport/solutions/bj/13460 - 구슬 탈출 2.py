# -*- coding: utf-8 -*-
#!/usr/bin/python

# https://www.acmicpc.net/problem/12100

# #NYAN NYAN
#░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
#░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
#░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
#░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
#░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
#░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
#░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
#░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
#░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
#░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
#░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
#░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
#░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

false = False
true = True
null = None
# import math
TEST = false
INPUT_FILE_PATH = ''
try:
    import sys
    for arg in sys.argv:
        if(arg == 'test'):
            print('test mode')
            TEST = True
            print(sys.version)
            if(len(sys.argv)>=2):
                print('input file path:')
                print(sys.argv[2])
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


class memoized(object, ):
    "Decorator. Caches a function's return value each time it is called.\n\tIf called later with the same arguments, the cached value is returned\n\t(not reevaluated).\n\t"

    def __init__(self, func):
        self.func = func
        self.cache = {}

    def __call__(self, *args):
        if (not isinstance(args, collections.Hashable)):
            return self.func(*args)
        if (args in self.cache):
            return self.cache[args]
        else:
            value = self.func(*args)
            self.cache[args] = value
            return value

        def __repr__(self):
            "Return the function's docstring."
            return self.func.__doc__

        def __get__(self, obj, objtype):
            'Support instance methods.'
            return functools.partial(self.__call__, obj)


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
    return list(map(int, input().strip().strip(' ').split(' ')))

def rsa():
    return list(map(str, input().strip().strip('\n').split(' ')))

# def create2dArray(y,x,val=False):
#     arr = [val]*x
#     for xx in range(x):
#         if(y == 0):
#             arr[xx] = []
#         else: arr[xx] = [val]*y
#     return arr

def create2DArray(rows,cols,val=False):
    # if(TEST):
    #     return create2DNumpyZeroArray(rows, cols, type(val))
    return [[val for c in range(cols)] for r in range(rows)]

def create2DNumpyZeroArray(rows, cols, dtype):
    import numpy as np

    return np.zeros((rows,cols), dtype=dtype)

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

def join(targetType, sourceList):
    return ''.join(map(targetType, sourceList))

def getnext(n, k):
    if(n==k):
        return 1
    else:
        return k+1

def genNums(n):
    import random
    arr = []
    for i in range(n):
        arr.append(random.randint
        (0, 100000))
    return arr

# ordCache={}
# def getD(c):
#     global ordCache
#     if(c in ordCache):
#         return ordCache[c]
#     ordCache[c] = ord(c) - 96
#     return ordCache[c]

@memoized
def getD(c):
    return ord(c) - 96

@memoized
def getCh(o):
    while(o<ord('a')):
        o+=26
    while(o>ord('z')):
        o-=26
    return chr(o)

def isInBound(cy,cx,y,x):
    if(cx<0 or cy<0 or cx>=x or cy>=y):
        return False
    return True
#      l  d  r  u    
dx = [-1,-0,+1,+0]
dy = [-0,-1,+0,+1]

def solve():
    from collections import defaultdict
    cache = defaultdict(lambda: -1)
    N, M = ria()
    goalpos = (-1,-1)
    rpos = (-1,-1)
    bpos = (-1,-1)
    crpos = (-1,-1)
    cbpos = (-1,-1)

    maps = create2DArray(N,M,'x')
    moves = [create2DArray(N,M,('x','x')),create2DArray(N,M,('x','x')),create2DArray(N,M,('x','x')),create2DArray(N,M,('x','x'))]
    for y in range(N):
        ins = rsa()[0]
        for x in range(M):
            maps[y][x] = ins[x]
            if(ins[x] == 'O'):
                goalpos = (y,x)
            elif(ins[x] == 'R'):
                rpos = (y,x)
            elif(ins[x] == 'B'):
                bpos = (y,x)
            
    it(maps)

    minv = 99999

    def nextPos(pos, direction):
        y,x = pos
        return y+dy[direction], x+dx[direction]

    def prevPos(pos, direction):
        y,x = pos
        return y-dy[direction], x-dx[direction]

    def nextMove(pos, direction):
        y,x = pos
        cur = maps[y][x]
        if(moves[direction][y][x] != ('x','x')):
            return moves[direction][y][x]
        if(cur == '#'):
            moves[direction][y][x] = ('i','i') # immovable
            return moves[direction][y][x]
        if(cur == '.' or cur=='B' or cur=='R'):
            # 다음 위치가 가리키는 대상으로 타게팅시키고, 리턴한다
            npos = nextPos(pos, direction)
            if(maps[npos[0]][npos[1]]=='#'):
                moves[direction][y][x] = pos
                return moves[direction][y][x]
            if(maps[npos[0]][npos[1]] == 'O'):
                moves[direction][y][x] = npos
                return moves[direction][y][x]
            moves[direction][y][x] = nextMove(npos, direction)

            return moves[direction][y][x]



    def preMove():
        for d in range(4):
            for y in range(N):
                for x in range(M):
                    nextMove((y,x), d)

    def compDir(apos, bpos, direction):
        # 해당 방향에 대해 두 물체의 상대적 위치를 비교
        # -1 : a가 더 해당 방향에 있다.
        # 0 : 다른 위상에 있다.
        # 1 : b가 더 해당 방향에 있다.
        if(dx[direction] == 0):
            # 세로 비교.
            if(apos[1] != bpos[1]):
                return 0
            return (apos[0] - bpos[0]) * dy[direction]
        else:
            # horizontal
            if(apos[0] != bpos[0]):
                return 0
            return (apos[1] - bpos[1]) * dx[direction]
        return 9999

    def handleMove(direction):
        nonlocal crpos,cbpos
        # it(crpos, cbpos)
        compv = compDir(crpos, cbpos, direction)
        # it('compv', compv)
        crpos = moves[direction][crpos[0]][crpos[1]]
        cbpos = moves[direction][cbpos[0]][cbpos[1]]
        # 충돌 검사: 해당 방향에 덜 가깝던 물체를 이전 위치로 옮긴다.
        # 부족하다! 특정 위치에 가로로 가다가 걸려있는 물체에 나중에 다른 공이 와서 걸릴 수도 있음을 고려하지 못했다! 이러한 경우 어떻게 되는가??
        if(crpos == cbpos and crpos != goalpos):
            if(compv > 0):
                cbpos = prevPos(cbpos, direction)
            elif(compv < 0):
                crpos = prevPos(crpos, direction)


    def dfs(rpos, bpos, cnt):
        # cachev = cache[(rpos, bpos, cnt)]
        # if(cachev!=-1):
        #     return cachev
        if(cnt>10):
            return
        
        if(bpos == goalpos):
            return

        if(rpos == goalpos):
            if(cnt < minv):
                it('update cnt')
                minv = cnt
            return
        
    

        
    from itertools import product

    it(goalpos)
    preMove()
    it('moves')
    # print2DArray(moves[0])

    for v in product([0,1,2,3], repeat=10):
        # it(v)
        crpos = rpos
        cbpos = bpos
        cnt = 0
        for j,m in enumerate(v):
            cnt+=1

            if(cache[(crpos, cbpos)]!= -1):
               if(cnt > cache[(crpos, cbpos)]):
                   break 
            cache[(crpos, cbpos)] = cnt

            if(cnt>10):
                break
            
            handleMove(m)
            
            if(cbpos == goalpos):
                break

            if(crpos == goalpos):
                if(cnt < minv):
                    it('update cnt', cnt)
                    minv = cnt
                break
        pass

    print(minv if minv<99990 else -1)
    pass


    

solve()
# import profile
# profile.run("solve()")

