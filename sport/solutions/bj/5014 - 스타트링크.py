#!/usr/bin/python
# -*- coding: utf-8 -*-

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


def it(args):
    if(TEST):
        print(args)
    # print(args, vargs)


def floatEqual(a, b):
    diff = math.fabs(a-b)
    if(diff < 1e-10):
        return True
    else:
        return diff <= 1e-8 * max(math.fabs(a), math.fabs(b))

def ria():
    return list(map(int, input().strip(' ').split(' ')))

def solve():
    #https://www.acmicpc.net/problem/5014
    
    [f,s,g,u,d] = ria()
    # f 총 f층
    # s 현재 층
    # g 스타트링크 있는 층
    # u 위로 u층
    # d 아래로 d층
    it([f,s,g,u,d])
    
    # 총인, f층이 있다는 것은, 층이 더 많을때 갈 수 있더라도 층이 모자라 실패하는 경우가 있다는 것.
    # 탐욕적으로 하되, 기존에 들렀던 층에 도달한다면 결국 뺑뺑이를 한다는 것이므로 실패시키면 어떨까? 나쁘지 않을 듯 하지만, 총 층이 백만개까지 가능하므로 만약 1층씩 올라가거나 내려가게 되면 곤란해진다. 그러면 최초로 방향을 바꿀 때부터 visited를 쓴다면? u가 1백만이라 한번에 올라가버리고 1층씩 내려오는 경우가 있을수도 있다. 그러면 방향을 두 번 바꿀 때부터 저장해보자.

    turned = 0
    turn = 0
    visited = {}

    befDirection = 0
    direction = g - s
    while(True):
        it(['s, g, turn', s, g, turn])
        if(turned >= 2 or turn % 100 == 0):
            it(['turned: ' , turned, 'turn ', turn])
            if(s in visited.keys()):
                print('use the stairs')
                break
            else:
                visited[s] = 1
            pass
        direction = g - s
        if(befDirection == 0):
            befDirection = direction
        elif(befDirection > 0 and direction < 0):
            turned +=1
            befDirection = -1
        elif(befDirection < 0 and direction > 0):
            turned+=1
            befDirection = +1
            pass
        if(direction == 0):
            print(turn)
            break
        elif(direction > 0):
            s+=u
            turn+=1
        elif(direction < 0):
            s-=d
            turn+=1
            pass
    
    pass


solve()
