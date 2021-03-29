# -*- coding: utf-8 -*-
#!/usr/bin/python

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

from sys import stdin
from collections import deque
import copy
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


def solve():
    global val
    n=ria()[0]
    arr=ria()
    arr.sort()
    m=ria()[0]
    checks=ria()
    val=0
    ans=[]

    def binsearch(left,right):
        global val
        cleft,cright=left,right
        while(cleft<cright):
            # it(cleft, cright)
            cmid=(cleft+cright)//2
            midval=arr[cmid]
            if(val>midval):
                cleft=cmid+1
            elif(val<midval):
                cright=cmid
            else:
                return True
        return False
            
    for i in range(m):
        val=checks[i]
        ans.append(binsearch(0, n))
            
    for i,v in enumerate(ans):
        print(1 if v else 0)
    pass


solve()
# import profile
# profile.run("solve()")
