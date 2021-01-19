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

def solve():
    # 
    n,m=ria()
    mat=create2DArray(n,m,0)
    for r in range(n):
        mat[r]=ria()
    # just log all 1,1,1,1 square and redo that sequence. (greedy)
    # if two same, pass.
    # 50*50 so max 2500 so time is enough
    # this is not toggle problem so greedy is no problem.

    seq=[]
    dx=[0,0,+1,+1]
    dy=[0,+1,0,+1]
    # construct seq
    for r in range(n-1):
        for c in range(m-1):
            AllOne=True
            for i in range(4):
                nr,nc=r+dy[i],c+dx[i]
                if(nr<0 or nr>=n or nc<0 or nc>=m):
                    AllOne=False
                    break
                if(mat[nr][nc]!=1):
                    AllOne=False
            if(AllOne):
                seq.append([r+1,c+1])
    # check equal
    b=create2DArray(n,m,0)
    for s in seq:
        r,c=s
        r,c=r-1,c-1
        for i in range(4):
            nr,nc=r+dy[i],c+dx[i]
            b[nr][nc]=1
    Same=True
    for r in range(n):
        for c in range(m):
            if(mat[r][c]!=b[r][c]):
                Same=False
    if(Same):
        print(len(seq))
        for s in seq:
            print(*s)
    else:
        print(-1)
    pass

solve()
# import profile
# profile.run("solve()")