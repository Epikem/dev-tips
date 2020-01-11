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
    # return list(map(int, input().strip(' ').split(' ')))
    return list(map(int, input().split(' ')))

from sys import stdin
input=stdin.readline
 

def solve():
    q = int(input())
    # q = ria()[0]
    for i in range(q):
        # it('stepstepstepstepstep')
        [n,k] = ria()
        # it(n,k)
        arr = ria()

        cands = []
        oddsCount = 0
        candCount = 0
        # ans = ''
        # for j in range(n):
        #     if(arr[j] % 2 == 1):
        #         # odds.append(j)
        #         oddsCount+=1
        #         if(candCount<k-1):
        #             candCount+=1
        #             ans = ans + str(j+1) + ' '
        #         pass
        for j, a in enumerate(arr, start=1):
            if(a % 2 == 1):
                # odds.append(j)
                oddsCount+=1
                if(candCount<k-1):
                    candCount+=1
                    # ans = ans + str(j) + ' '
                    cands.append(j)
                pass
        # ans = ans + str(n)
        cands.append(n)

        if(k <= oddsCount and (oddsCount-k) % 2 == 0):
            print('YES')
            # print(' '.join(map(str, cand)))
            print(*cands)


        else:
            print('NO')
            pass

        pass

    pass


solve()
