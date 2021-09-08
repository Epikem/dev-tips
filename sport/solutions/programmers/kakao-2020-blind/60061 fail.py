# -*- coding: utf-8 -*-
#!/usr/bin/python

# 풀이는 `solve()` 함수에 있습니다.
# #NYAN NYAN
# ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
# ░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
# ░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
# ░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
# ░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
# ░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
# ░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
# ░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
# ░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
# ░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
# ░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
# ░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
# ░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
# ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

from operator import add
from collections import defaultdict
from random import betavariate
from sys import stdin
from collections import deque
import copy
false = False
true = True
null = None
# import math
TEST = False
try:
    import sys
    for arg in sys.argv:
        if(arg == 'test'):
            print('test mode')
            TEST = True
            print(sys.version)
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
libnames = ['functools', 'math', 'collections', 'numpy']
# libnames = ['math']

AddImports(libnames)
IntellisenseHint = False
if IntellisenseHint:
    import functools
    import math
    import collections
    import numpy
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


def rfa():
    return list(map(float, input().strip().strip(' ').split(' ')))


def rida():
    return list(map(lambda x: int(x)-1, input().strip().strip(' ').split(' ')))


def rsa():
    return list(map(str, input().strip().strip('\n').split(' ')))

# def create2dArray(y,x,val=False):
#     arr = [val]*x
#     for xx in range(x):
#         if(y == 0):
#             arr[xx] = []
#         else: arr[xx] = [val]*y
#     return arr


def tryCreate2DZeroArray(rows, cols):
    try:
        import numpy as np
        return create2DNumpyZeroArray(rows, cols, int)
    except:
        return create2DArray(rows, cols, 0)


def create2DArray(rows, cols, val=False):
    return [[val for c in range(cols)] for r in range(rows)]


def create2DNumpyZeroArray(rows, cols, dtype):
    import numpy as np

    return np.zeros((rows, cols), dtype=dtype)


def create3DArray(zs, ys, xs, val=False):
    return [[[val for x in range(xs)] for y in range(ys)] for z in range(zs)]


def print2DArray(array):
    for r in range(len(array)):
        it(*array[r])


def takeFirst(x):
    return x[0]


def takeSecond(x):
    return x[1]


input = stdin.readline
# import queue

# from itertools import permutations
sys.setrecursionlimit(10000)

def join(targetType, sourceList):
    return ''.join(map(targetType, sourceList))


def getnext(n, k):
    if(n == k):
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
    while(o < ord('a')):
        o += 26
    while(o > ord('z')):
        o -= 26
    return chr(o)


def numToBits(num):
    from collections import deque
    bits = deque()
    while(num > 0):
        bits.appendleft(num % 2)
        num = num//2
    return bits


def numToBin(num):
    return bin(num)


def bitsToNum(bits):
    ret = 0
    for i, v in enumerate(reversed(bits)):
        ret += 2 ** (i) if v == 1 else 0
    return ret
    
class dotdict(dict):
    """dot.notation access to dictionary attributes"""
    __getattr__ = dict.get
    __setattr__ = dict.__setitem__
    __delattr__ = dict.__delitem__

def binToNum(binary: str):
    return int(binary, 2)

def getDigitCnt10(num):
    return len(str(num))

def getBitCnt(num):
    return len(bin(num)) - 2

class point2d:
    def __init__(self, r, c):
        self.r = r
        self.c = c
    
    def __str__(self):
        return 'point2d({}, {})'.format(self.r, self.c)

    def to_idx(self, mr, mc = 99999999):
        if(self.r<0 or self.c<0 or self.r>=mr or self.c>=mc):
            return -1
        return self.r * mr + self.c
    
    def from_idx(idx, mr, mc = 1):
        p = point2d(idx // mr, idx % mr)
        return p

# 검사 
def validate(r,c,a,maps):
    valid = False
    if a == 0:
        # 1. 바닥 위
        if r == 0:
            valid = True
            pass
        else:
            # 2. 보의 한쪽 끝 위
            if c-1>=0 and maps[r][c-1] == 1:
                valid = True
                pass
            elif maps[r][c] == 1:
                valid = True
                pass

            # 3. 다른 기둥 위
            if r-1 >= 0 and maps[r-1][c] == 0:
                valid = True
                pass
            pass
        pass
    # 보 설치 시도
    elif a == 1:
        # 1. 한쪽 끝이 기둥 위
        if r-1>=0 and maps[r-1][c] == 0:
            valid = True
            pass
        if r-1>=0 and maps[r-1][c+1] == 0:
            valid = True
            pass

        # 2. 양쪽 끝이 보
        if c-1>=0 and maps[r][c-1] == 1 and maps[r][c+1] == 1:
            valid = True
            pass
        pass
    return valid

def solve(n, build_frame):
    # pillar 기둥: 0
    # bridge 보: 1
    maps = create2DArray(150,150,-1)
    nodes = []
    for i,build in enumerate(build_frame):
        x,y,a,b = build
        r,c=y,x

        valid = True
        maps_before = maps.copy()

        # 설치 모드
        if b == 1:
            nodes.append((r,c,a))
            maps[r][c] = a
            
            # check valid for all nodes
            for rr,cc,aa in nodes:
                valid = validate(rr,cc,aa,maps)
                if not valid:
                    break
                pass
            if not valid:
                maps = maps_before
                nodes.remove((r,c,a))
                pass
        else:
            # 삭제 모드
            # remove (r,c,a) from nodes
            if (r,c,a) in nodes:
                nodes.remove((r,c,a))
                maps[r][c] = -1
                pass
            else:
                continue

            # check valid for all nodes
            for rr,cc,aa in nodes:
                valid = validate(rr,cc,aa,maps)
                if not valid:
                    break
                pass
            if not valid:
                maps = maps_before
                nodes.append((r,c,a))
                pass
            pass
    # make list of structures from nodes
    structures = []
    for r,c,a in nodes:
        structures.append([c,r,a])
        pass
    print(structures)
    return sorted(structures)
    

solution = solve

# build frame, result = [[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]	[[1,0,0],[1,1,1],[2,1,0],[2,2,1],[3,2,1],[4,2,1],[5,0,0],[5,1,0]]
n, build_frame, result = 	5, [[0, 0, 0, 1], [2, 0, 0, 1], [4, 0, 0, 1], [0, 1, 1, 1], [1, 1, 1, 1], [2, 1, 1, 1], [3, 1, 1, 1], [2, 0, 0, 0], [1, 1, 1, 0], [2, 2, 0, 1]], [[0,0,0],[0,1,1],[1,1,1],[2,1,1],[3,1,1],[4,0,0]]

ans = solve(n, build_frame)

# # debug
print(ans, "==", result)
assert(ans == result)


