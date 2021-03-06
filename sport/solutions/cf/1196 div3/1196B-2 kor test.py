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

def solve():
    q = ria()[0]
    for i in range(q):
        it('stepstepstepstepstep')
        [n,k] = ria()
        # it(n,k)
        arr = ria()
        #덱스를 띄워도 될 것이다. 세개로 나눠야 하는데 7 18 3 14 1 3 5 이렇게 되있다면 
        odds = []
        cand = []
        for j in range(len(arr)):
            if(arr[j] % 2 == 1):
                odds.append(j)
                if(j<= k-1):
                    cand.append(j+1)
                pass
        cand.append(n)
        # it(odds)
        # odds길이와 k가 같으면 가능, k가 더 크면 불가능

        if(k <= len(odds) and (len(odds)-k) % 2 == 0):
            print('YES')
            # for od in range(k-1):
            #     cand.append(odds[od]+1)
            # cand.append(n)
            # it(cand)
            print(' '.join(map(str, cand)))


        else:
            print('NO')
            pass

        pass

    pass


solve()
