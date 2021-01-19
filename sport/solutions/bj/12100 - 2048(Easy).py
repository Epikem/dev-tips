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

#     l,d,r,u
dx = [-1,0,+1,0]
dy = [0,-1,0,+1]
#     r,u,l,d
def solve():
    N = ria()[0]

    maps = create2DArray(N, N, 0)
    maxv = -1

    for y in range(N):
        maps[y] = ria()

    it(maps)

    def getDiff(direction):
        return direction - 1 if direction % 2 == 0 else -1 * (direction - 2)

    def isHorizontal(direction):
        return direction % 2 == 0

    def findMax(state):
        nonlocal maxv
        for y in range(N):
            for x in range(N):
                if(state[y][x] > maxv):
                    it('max update at : ',y,x,maxv,state[y][x])
                    maxv=state[y][x]

    def handleMove(state, direction):
        # 움직이려는 방향으로부터, 반대 방향으로, 
        # direction = (direction+2) % 4
        for rows in range(N):
            lastEmptyX=-1
            lastBlockX=-1
            for x in range(N):
                cx = N-1-x if direction==0 or direction==3 else x
                
                a,b = (rows,cx) if isHorizontal(direction) else (cx,rows)
                c,d = (rows,lastBlockX) if isHorizontal(direction) else (lastBlockX, rows)
                e,f = (rows,lastEmptyX) if isHorizontal(direction) else (lastEmptyX,rows)
                if(state[a][b]>0):
                    # there is a block
                    if(lastBlockX != -1):
                        # do merge
                        if(state[c][d] == state[a][b]):
                            # it('merge', cx, lastBlockX, lastEmptyX)
                            state[c][d] += state[a][b]
                            state[a][b] = 0
                            lastEmptyX = lastBlockX + getDiff(direction)
                            lastBlockX = -1
                            continue
                    lastBlockX = cx

                if(lastEmptyX != -1 and state[a][b]>0):
                    # there is no block. use lastEmptyX
                    state[e][f] = state[a][b]
                    if(cx != lastEmptyX):
                        state[a][b] = 0
                    # 0->-1, 2->+1
                    lastBlockX = lastEmptyX
                    lastEmptyX += getDiff(direction)
                    
                if(lastEmptyX==-1 and state[a][b]==0):
                    lastEmptyX = cx
        return state

    from itertools import product

    for i,v in enumerate(product(range(4), range(4),range(4),range(4),range(4))):
        # it(v)
        curState = copy.deepcopy(maps)
        curState = handleMove(curState, v[0])
        curState = handleMove(curState, v[1])
        curState = handleMove(curState, v[2])
        curState = handleMove(curState, v[3])
        curState = handleMove(curState, v[4])
        findMax(curState)
    print(maxv)

    

solve()
# import profile
# profile.run("solve()")

