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

def join(targetType, sourceList):
    return ''.join(map(targetType, sourceList))

def solve():
    import itertools

    n=ria()[0]
    arr=input().strip().split(' ')
    it(arr)
    fromTop=[]
    fromBot=[]
    t=9
    b=0
    for i in range(n+1):
        fromTop.append(t)
        t-=1
        fromBot.append(b)
        b+=1

    it(fromTop)
    it(fromBot)
    maxv=0
    maxstr=''
    minv=99999999999
    minstr=''
    permutations=itertools.permutations(fromTop)
    for li1 in permutations:
        ok=True
        for i in range(n):
            if((arr[i]=='<' and li1[i] < li1[i+1]) or (arr[i]=='>' and li1[i] > li1[i+1])):
                pass
            else:
                ok=False
            pass
        if(ok):
            strv=''.join(map(str, li1))
            num=int(strv)
            if(maxv<num):
                maxv=num
                maxstr=strv
                break
        
    permutations=itertools.permutations(fromBot)
    for li1 in permutations:
        ok=True
        for i in range(n):
            if((arr[i]=='<' and li1[i] < li1[i+1]) or (arr[i]=='>' and li1[i] > li1[i+1])):
                pass
            else:
                ok=False
            pass
        if(ok):
            strv=''.join(map(str, li1))
            num=int(strv)
            if(minv>num):
                minv=num
                minstr=strv
                break
    print(maxstr)
    print(minstr)
    pass

solve()
# import profile
# profile.run("solve()")

