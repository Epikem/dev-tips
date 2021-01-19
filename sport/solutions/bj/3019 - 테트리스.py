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

# https://www.acmicpc.net/problem/3019

SIZE=300010
MOD=998244353

# 일단 방법의 수를 구해야 하므로,
# 방법의 수는 현재 블록을 놓을 수 있는 형태의 칸수 패턴들 마다 1씩 증가한다.
# 그런데, 가장 큰 문제는 블록 및 블록 회전을 구현하는 것.
# 회전까지 구현하려면 일일히 하면 너무 노가다일거 같은데.
# 그냥 4개 블록을 끊어지지만 않게 구현한 모든 가지수가 필요한 것 아닌가?
# 그걸 어떻게 할지가 문제다.
# 사실 형태상 가로로 밀 수 있다면 모든 가로 패턴이, 세로로 밀 수 있다면 모든 세로 패턴을 구할 수 있는데,
# 어떤 블록은 180도 회전하면 같은 모양이 되고, 어떤 블록들은 아니다. 
# 그렇게 모든 회전까지 포함한 가지수들을 구현해서,
# 그리고 바닥에 놓을 수 있는지는 그 가지수들의 패턴을 역이용해서 
# 가장 아래에 있는 블록 기준 다른 아래에 돌출된 블록들의 상대적 위치를 기록하면
# 될 거 같은데.. 구현이 어려울 거 같다.
# 아무래도 지금은 블록들을 생성을 어떻게 해야 할 지 감이 안 오는데,
# 각 블록의 번호의 회전 상태에 따라 아래의 패턴만 저장해서 비교해도 되지 않을까?


def solve():
    bottomPatterns={}
    bottomPatterns[1]=[[0],[0,0,0,0]]
    bottomPatterns[2]=[[0,0]]
    bottomPatterns[3]=[[0,0,-1],[-1,0]]
    bottomPatterns[4]=[[-1,0,0],[0,-1]]
    bottomPatterns[5]=[[0,0,0],[0,-1],[-1,0,-1],[-1,0]]
    bottomPatterns[6]=[[0,0,0],[0,0],[0,-1,-1],[-2,0]]
    bottomPatterns[7]=[[0,0,0],[0,-2],[-1,-1,0],[0,0]]
    
    patterns={1:[],2:[],3:[],4:[]}

    c,p=ria()
    maps=ria()
    for i in range(c):
        if(i+4<=c):
            patterns[4].append(maps[i:i+4])
        if(i+3<=c):
            patterns[3].append(maps[i:i+3])
        if(i+2<=c):
            patterns[2].append(maps[i:i+2])
        if(i+1<=c):
            patterns[1].append(maps[i:i+1])
    # it(patterns)

    ans = 0
    for patArr in bottomPatterns[p]:
        pattern=patterns[len(patArr)]
        for pat in pattern:
            copyPat=pat[:]
            # if(len(patArr) != len(copyPat)):
            #     it('ERROR')
            base=copyPat[0]+patArr[0]
            success=True
            # it('patArr: ', patArr, ' pattern: ', pat)
            for i in range(len(copyPat)):
                copyPat[i]+=patArr[i]
                if(base != copyPat[i]):
                    # it('Fail for this.')
                    success=False
                    break
            if(success):
                ans+=1
    print(ans)
    pass

solve()
# import profile
# profile.run("solve()")