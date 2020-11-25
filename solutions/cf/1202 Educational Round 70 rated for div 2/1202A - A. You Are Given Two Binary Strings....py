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

def solve():
    T = ria()[0]
    for t in range(T):
        x = rs()
        y = rs()
        # it(x,y)
        last1ofy = y.rindex('1')
        last1ofx = x.rindex('1', 0, len(x)-last1ofy)
        posx = len(x)-last1ofx-1
        posy = len(y)-last1ofy-1
        # it(last1ofx, last1ofy)
        # it('pos', posx,posy)
        print(posx-posy)
        # y의 이진 표현을 얼마만큼 왼쪽 쉬프트해서, 
        # x+y결과에 오른쪽 0의 개수를 최대로 늘리면 될거 같은데, 
        # 사전 순으로 0과 1의 패턴이 같다면, 짧은게 우선된다는데,
        # 괜히 0의 개수를 더 늘리려다 더 짧은것에 질 수도 있나?
        
        # 0011
        # 00001 둘 중에 0011이 더 앞이다. 이렇게 되는 경우가 생길 수 있나?
        # 있다.

        # 1100= 1000+100
        # 10000=1000+1000
        # 잠깐, 아니다 0011이 더 뒤다. 
        # 00001
        # 0011
        # 따라서 일단 0을 최대한 늘리는거로 해보자.
        ##  x와 y의 길이는 최대 백만. 꽤 길다.
        # 근데 잘 생각해보면 어차피 x의 첫 1과 y의 첫 1을 맞추기만 하면 되지 않나.
        # 그 두개가 안 맞을 경우 어차피 남은 녀석의 1이 더 앞에 나와버려서 사전순상 불리하게 될
        # 것이므로. y의 가장 마지막 1을 x의 가장 마지막 1에 맞추게 하는 k를 고르면 될거 같다.
        
        # 근데 이렇게 하면 문제가, 예제 2를 못 푼다.
        # k가 0이어도 매치가 안 되어서 아예 매치 가능한 다음 1에다 마지막 1을 맞춘다.
        # 즉 맞는 선에서 최초로 맞추게 하면 될듯?
    pass

solve()