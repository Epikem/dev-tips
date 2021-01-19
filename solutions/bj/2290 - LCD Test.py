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

def create2dArray(x,y,val=False):
    arr = [val]*y
    for yy in range(y):
        if(x == 0):
            arr[yy] = []
        else: arr[yy] = [val]*x
    return arr

from sys import stdin
input=stdin.readline
# from itertools import permutations

lines = create2dArray(0,30)    # 최소 5 ~ 최대 23
digits = []     # 수
switches = [True]*7
def solve():
    s,n=ria()
    digits = list(str(n))
    it(digits)
    def saveBar():
        for i in range(2*s+3):
            lines[i].append(' ')
    def saveDigit():
        lines[0].append(' ')
        for i in range(s):
            lines[0].append('-' if switches[0] else ' ')
        lines[0].append(' ')
        for l in range(1, s+1):
            lines[l].append('|' if switches[1] else ' ')
            for i in range(s):
                lines[l].append(' ')
            lines[l].append('|' if switches[2] else ' ')
        lines[s+1].append(' ')
        for i in range(s):
            lines[s+1].append('-' if switches[3] else ' ')
        lines[s+1].append(' ')
        for l in range(s+2, 2*s+2):
            lines[l].append('|' if switches[4] else ' ')
            for i in range(s):
                lines[l].append(' ')
            lines[l].append('|' if switches[5] else ' ')
        lines[2*s+2].append(' ')
        for i in range(s):
            lines[2*s+2].append('-' if switches[6] else ' ')
        lines[2*s+2].append(' ')
    def processDigit(digit):
        for i in range(7):
            switches[i]=True
        if(digit=='1'):
            # s+2의 가로 중 s+1개는 빈칸, 1개가 1, 그 후 공백 1칸.
            # 길이를 늘어나게 할 수 있으려면 어떤 식으로 처리해야 할까?
            # 
            switches[0]=False
            switches[1]=False
            # switches[2]=True
            switches[3]=False
            switches[4]=False
            # switches[5]=True
            switches[6]=False
            pass
        elif(digit=='2'):
            switches[1] = False
            switches[5] = False
        elif(digit=='3'):
            switches[1] = False
            switches[4] = False
        elif(digit=='4'):
            switches[0] = False
            switches[4] = False
            switches[6] = False
        elif(digit=='5'):
            switches[2] = False
            switches[4] = False
        elif(digit=='6'):
            switches[2] = False
        elif(digit=='7'):
            switches[1] = False
            switches[3] = False
            switches[4] = False
            switches[6] = False
        elif(digit=='9'):
            switches[4] = False
        elif(digit=='0'):
            switches[3] = False
        saveDigit()
        saveBar()

    for i in range(len(digits)):
        processDigit(digits[i])
    for i in range(len(lines)):
        print(''.join(lines[i]))
    pass

solve()