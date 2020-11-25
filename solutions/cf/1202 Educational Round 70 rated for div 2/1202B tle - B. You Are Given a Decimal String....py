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

def rs():
    return input().strip('\n')

def create2dArray(x,y,val=False):
    arr = [val]*y
    for yy in range(y):
        if(x == 0):
            arr[yy] = []
        else: arr[yy] = [val]*x
    return arr

from sys import stdin
input=stdin.readline
# import copy
# import queue

# from itertools import permutations
costs = create2dArray(10,10, 999)

def solve():
    # 각 자리마다의 위상 차이 (높은수 -> 낮은수의 경우 낮은수+10 - 높은수)를 계산해서,
    # 01, 11카운터의 경우, 1씩증가하면서 셀 것이다
    # 사실 각 자리수 차이마다 독립으로 보인다. 따라서 각 위상차들로 분해해서, 함수화해서
    # 그 합산을 합치면 될 듯하다.
    def calcDiff(a,b):
        return b-a if b>a else b+10-a
    def calcCost(diff,i,j):
        # i나 j중 최대한 빨리 diff를 만들 수 있는?
        # 섞어서 써야 하는 경우가 생길 수 있나?
        # 예를 들어 0->5인데, 2와 3이라면 분명 섞어서 써야 한다.
        # 그러면 이런 i와 j의 cost 조합으로 어떤 diff를 얼마의 cost로 할 수 있는지 정리한
        # cost배열을 dp기법으로 만들 수 있을거 같은데? 다익스트라와도 비슷.
        
        return costs[i][j][diff]
    def fillCost(i,j, ic, jc, origin, num):
        if(origin==num and (ic > 0 or jc > 0)):
            return
        if(ic > 10 or jc > 10): return
        if(i > j):
            costs[i][j][num] = costs[j][i][num]
            return
        
        co = ic+jc
        costs[i][j][num]=min(costs[i][j][num], co)
        costs[j][i][num]=min(costs[j][i][num], co)
        
        fillCost(i,j,ic+1,jc,origin, num+i if num+i<10 else num+i-10)
        fillCost(i,j,ic,jc+1,origin, num+j if num+j<10 else num+j-10)
        pass
    s = rs()
    ans = create2dArray(10,10,-1)
    
    for i in range(10):
        for j in range(10):
            # it('i,j', i, j)
            if(i>j):
                ans[i][j]=ans[j][i]
                continue
            costs[i][j] = [999]*10
            costs[j][i] = [999]*10
            fillCost(i,j,0,0,0,0)
            # it('s',s)
            sums = 0
            for c in range(len(s)-1):
                # it('sums',sums)
                # it('len s', len(s), s)
                sums+=calcCost(calcDiff(int(s[c]),int(s[c+1])),i,j)
            ans[i][j] = sums-len(s)+1 if sums<999 else -1
            pass

    # it(costs)
    for i in range(len(ans[0])):
        print(*ans[i])
    pass

solve()