false = False
true = True
null = None
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
libnames = ['fileinput', 'codecs', 'operator', 'functools', 'math', 'io', 'platform', 'collections', 'mmap', 'logging', 'logging.handlers']
# libnames = ['math']

AddImports(libnames)
IntellisenseHint = False
if IntellisenseHint:
    import fileinput
    import codecs
    import operator
    import functools
    import math
    import io
    import platform
    import collections
    import mmap
    import logging
    import logging.handlers
    # import defs

class memoized(object, ):
    "Decorator. Caches a function's return value each time it is called.\n\tIf called later with the same arguments, the cached value is returned\n\t(not reevaluated).\n\t"

    def __init__(self, func):
        self.func = func
        self.cache = {}

    def __call__(self, *args):
        if (not isinstance(args, collections.Hashable)):
            return self.func(*args)
        if (args in self.cache):
            return self.cache[args]
        else:
            value = self.func(*args)
            self.cache[args] = value
            return value

        def __repr__(self):
            "Return the function's docstring."
            return self.func.__doc__

        def __get__(self, obj, objtype):
            'Support instance methods.'
            return functools.partial(self.__call__, obj)

def it(args):
    if(TEST): print(args)
    # print(args, vargs)

def floatEqual(a,b):
    diff = math.fabs(a-b)
    if(diff < 1e-10): return True
    else: return diff <= 1e-8 * max(math.fabs(a), math.fabs(b))

def ria():
    return list(map(int,input().strip(' ').split(' ')))

def solve():
    cache = {}

    li = [False]* 1001
    tris = [1]*1001
    cands = [9999]*1001
    dons = [9999]*1001

    for i in range(1, 1001):
        tris[i] = tris[i-1] + i+1
        pass
    it(tris)
    for i in range(1000):
        for j in range(1000):
            [a,b] = [tris[i], tris[j]]
            if(a+b<=1000):
                cands[a+b] = a+b
    for i in range(1000):
        for j in range(1000):
            [a,b] = [cands[i], tris[j]]
            if(a+b <= 1000):
                dons[a+b] = 1

    it(dons)
    T = ria()[0]
    for _ in range(T):
        n = ria()[0]
        print(1 if dons[n]==1 else 0)

    pass



solve()