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

def debug2DArray(array):
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

def solve():
    N, M = ria()
    def calcCost(pos):
        # B first
        mins = 9999999
        bal1 = 0
        bal2 = 0
        for rr in range(8):
            for cc in range(8):
                y,x = rr+pos[0],cc+pos[1]
                a,b = (rr+cc)%2, (rr+cc+1)%2
                bal1+=a if maps[y][x]=='B' else b
                bal2+=b if maps[y][x]=='B' else a

        mins = min(mins, abs(bal1))
        mins = min(mins, abs(bal2))
        return mins

    maps = create2DArray(N,M,'x')
    cnts = [0,0]
    for r in range(N):
        ins = rsa()[0]
        for c in range(M):
            maps[r][c] = ins[c]
            if(ins[c] == 'B'):
                cnts[0]+=1
            else:
                cnts[1]+=1

    debug2DArray(maps)
    it(cnts)
    
    mins = 9999999
    for r in range(N-8+1):
        for c in range(M-8+1):
            mins = min(mins, calcCost((r,c)))
            # it(mins)
    it('mins')
    print(mins)
    pass

solve()
# import profile
# profile.run("solve()")

