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


libnames = ['fileinput', 'codecs', 'operator', 'functools', 'math',
            'io', 'platform', 'collections', 'mmap', 'logging', 'logging.handlers']
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
    cache = {}

    li = ria()
    it(li)

    [N, M, H] = li
    lis = []

    moves = [0]*(N+1)

    for m in range(M):
        [a,b] = ria()
        lis.append([a-1,b-1])
        pass
        
    lis.sort(key=lambda x:x[1])
    it(lis)
    for i in range(len(lis)):
        # it(i)
        # it(lis[i])
        k = lis[i][1]

        moves[k]+=1
        moves[k+1]-=1        
        pass
    it(moves)
    inSession = false
    maxAbsDist = 0
    sessionDist = 0
    sessionPlus = 0
    sessionMinus = 0
    sessionPlusMax = 0
    # lis.sort(lambda x:x[1])
    
    # it(lis)
    it('[i, inSession, moves[i], sessionDist, sessionPlus, sessionPlusMax]')
    for i in range(N):
        if(not inSession and moves[i]>0):
            inSession = true
            sessionDist += moves[i]
            sessionPlus += moves[i] if moves[i] > 0 else 0
            sessionMinus = 0
            pass
        else:
            sessionDist += moves[i]
            sessionPlus += moves[i] if moves[i] > 0 else 0
            sessionMinus += moves[i] if moves[i] < 0 else 0
            if(sessionDist == 0):
                sessionPlusMax+= max(abs(sessionPlus), abs(sessionMinus))
                inSession = false
                sessionPlus = 0
                sessionMinus = 0

                
        it([i, inSession, moves[i], sessionDist, sessionPlus, sessionPlusMax, sessionMinus])
        pass
    it(sessionPlusMax)
    if(sessionPlusMax >= 4 or sessionPlusMax == 0):
        print('-1')
    else:
        print(sessionPlusMax)
    pass


solve()
