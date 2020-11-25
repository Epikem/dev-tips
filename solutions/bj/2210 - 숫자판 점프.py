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

# https://www.acmicpc.net/problem/2210

SIZE=300010
MOD=998244353

# 5x5 크기 정도이므로, 주어진 대로 구현해도 될 거 같다.
# 임의의 위치에서 랜덤하게 움직이는 모든 경우의 수가 몇 가지 정도일까?
# 생각보다 상당히 많을거 같기도 한데, 길이도 6 제한이므로 괜찮지 않을까.

def solve():
    patset=set()
    dy=[0,0,+1,-1]
    dx=[+1,-1,0,0]
    maps=create2DArray(5,5,-1)
    for r in range(5):
        maps[r]=ria()
    def move(y,x,pat=[]):
        if(len(pat)==6):
            tup = tuple(pat)
            if(tup in patset):
                return
            patset.add(tup)
            return
        for i in range(4):
            ny,nx=y+dy[i],x+dx[i]
            # it('try ' ,ny, ' ' ,nx, ' ' , len(pat))
            if(ny<0 or ny>=5 or nx<0 or nx>=5):
                continue
            tmppat=pat[:]
            tmppat.append(maps[ny][nx])
            move(ny,nx,tmppat)
        pass

    for r in range(5):
        for c in range(5):
            move(r,c)
    
    # it(patset)
    print(len(patset))
    pass

solve()
# import profile
# profile.run("solve()")