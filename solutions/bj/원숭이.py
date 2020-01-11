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

from sys import stdin
input=stdin.readline
import copy
# import queue
from collections import deque

# from itertools import permutations
sys.setrecursionlimit(10000)

# https://www.acmicpc.net/problem/1600

minCount=999999

def solve():
    global minCount
    k = ria()[0]
    w,h=ria()
    maps=create2DArray(h+2,w+2,-1)
    ddx=[+2,+2,+1,+1,-1,-1,-2,-2]
    ddy=[+1,-1,+2,-2,+2,-2,+1,-1]
    dx=[+1,-1,0,0]
    dy=[0,0,+1,-1]
    costs=create3DArray(k+1,h+2,w+2,0)

    for hh in range(h):
        maps[hh]=ria()
    stateExample=('y','x','moveCount','usedKMoveCount')
    q = deque()
    initialState=(0,0,0)
    q.append(initialState)
    while(q):
        kCount,y,x = q.pop()
        # it('search', y,x,kCount)
        if(y==h-1 and x==w-1):
            print(costs[kCount][y][x])
            return
        if(kCount>k):
            continue
        
        for i in range(8):
            ny = y+ddy[i]
            nx = x+ddx[i]
            if(ny>=h or ny<0 or nx>=w or nx<0 or kCount+1>k):
                continue
            if(maps[ny][nx]==1):
                continue
            if(not costs[kCount+1][ny][nx]):
                costs[kCount+1][ny][nx]=costs[kCount][y][x]+1
                q.appendleft((kCount+1,ny,nx))
        for i in range(4):
            ny=y+dy[i]
            nx=x+dx[i]
            if(ny>=h or ny<0 or nx>=w or nx<0 or kCount>k):
                continue
            if(maps[ny][nx]==1):
                continue
            if(not costs[kCount][ny][nx]):
                costs[kCount][ny][nx]=costs[kCount][y][x]+1
                q.appendleft((kCount,ny,nx))
    print(-1)

    pass

solve()
# import profile
# profile.run("solve()")