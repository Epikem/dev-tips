# -*- coding: utf-8 -*-
#!/usr/bin/python

# #NYAN NYAN
# ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
# ░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
# ░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
# ░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
# ░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
# ░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
# ░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
# ░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
# ░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
# ░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
# ░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
# ░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
# ░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
# ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

from collections import defaultdict
from sys import stdin
from collections import deque
import copy
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
libnames = ['functools', 'math', 'collections', 'numpy']
# libnames = ['math']

AddImports(libnames)
IntellisenseHint = False
if IntellisenseHint:
    import functools
    import math
    import collections
    import numpy
    # import mmap
    # import logging
    # import logging.handlers
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
    return list(map(int, input().strip().strip(' ').split(' ')))


def rfa():
    return list(map(float, input().strip().strip(' ').split(' ')))


def rida():
    return list(map(lambda x: int(x)-1, input().strip().strip(' ').split(' ')))


def rsa():
    return list(map(str, input().strip().strip('\n').split(' ')))

# def create2dArray(y,x,val=False):
#     arr = [val]*x
#     for xx in range(x):
#         if(y == 0):
#             arr[xx] = []
#         else: arr[xx] = [val]*y
#     return arr


def tryCreate2DZeroArray(rows, cols):
    try:
        import numpy as np
        return create2DNumpyZeroArray(rows, cols, int)
    except:
        return create2DArray(rows, cols, 0)


def create2DArray(rows, cols, val=False):
    return [[val for c in range(cols)] for r in range(rows)]


def create2DNumpyZeroArray(rows, cols, dtype):
    import numpy as np

    return np.zeros((rows, cols), dtype=dtype)


def create3DArray(zs, ys, xs, val=False):
    return [[[val for x in range(xs)] for y in range(ys)] for z in range(zs)]


def print2DArray(array):
    for r in range(len(array)):
        it(*array[r])


def takeFirst(x):
    return x[0]


def takeSecond(x):
    return x[1]


input = stdin.readline
# import queue

# from itertools import permutations
sys.setrecursionlimit(10000)


def join(targetType, sourceList):
    return ''.join(map(targetType, sourceList))


def getnext(n, k):
    if(n == k):
        return 1
    else:
        return k+1


def genNums(n):
    import random
    arr = []
    for i in range(n):
        arr.append(random.randint
                   (0, 100000))
    return arr

# ordCache={}
# def getD(c):
#     global ordCache
#     if(c in ordCache):
#         return ordCache[c]
#     ordCache[c] = ord(c) - 96
#     return ordCache[c]


@memoized
def getD(c):
    return ord(c) - 96


@memoized
def getCh(o):
    while(o < ord('a')):
        o += 26
    while(o > ord('z')):
        o -= 26
    return chr(o)


def rsa():
    return list(map(str, input().strip().strip('\n').split(' ')))


class dictlist:
    def __init__(self):
        self.data = {}
        self.cur = {'val': None, 'prev': None, 'next': None}
        self.head = {'val': 'head', 'prev': None, 'next': self.cur}
        self.cur['prev'] = self.head
        self.size = 0

        # self.pos = -1

    def getList(self):
        pointer = self.head['next']
        ret = []
        while(pointer):
            if(pointer['val']):
                ret.append(pointer['val'])
            pointer = pointer['next']
        return ret

    def printList(self):
        pointer = self.head
        ret = []
        while(pointer):
            if(pointer == self.cur):
                ret.append('*')
            if(pointer['val']):
                ret.append(pointer['val'])
            pointer = pointer['next']
        print(' '.join(ret))

    def findNext(self):
        nextnode = self.cur['next']
        # assert(pos < self.size)
        return nextnode if nextnode != None else self.cur

    def findPrev(self):
        prevnode = self.cur['prev']
        # assert(pos < self.size)
        return prevnode if prevnode != None else self.cur

    def moveNext(self):
        nextnode = self.cur['next']
        self.cur = nextnode if nextnode != None else self.cur
        return self.cur

    def movePrev(self):
        # it('moving prev')
        prevnode = self.cur['prev']
        if(prevnode):
            if(prevnode['val'] == 'head'):
                return self.cur
            self.cur = prevnode if prevnode != None else self.cur
        return self.cur

    def add(self, val):
        # prev -> cur -> next
        # prev -> newnode -> cur
        prevnode = self.cur['prev']
        newnode = {'val': val, 'prev': prevnode, 'next': self.cur}
        if(prevnode):
            prevnode['next'] = newnode
        newnode['prev'] = prevnode
        newnode['next'] = self.cur
        self.cur['prev'] = newnode

        return newnode

    def remove(self):
        # pprev -> prev -> cur -> next
        # pprev -> cur -> next
        # if(not self.cur['val']):
        # if(self.cur['val'] == None):

        prevnode = self.cur['prev']
        pprevnode = prevnode['prev'] if prevnode else None

        if((not prevnode) or (not pprevnode)):
            return self.cur

        # it(f'deleting {prevnode["val"]}')

        pprevnode['next'] = self.cur
        self.cur['prev'] = pprevnode

        # self.cur = self.movePrev()
        # if(self.cur):
        #     it(f'deleting {self.cur["val"]}')
        #     if(self.cur['val'] == 'head'):
        #         return self.cur
        # prevnode = self.cur['prev']
        # nextnode = self.cur['next']
        # if(prevnode):
        #     prevnode['next'] = self.cur['next']
        #     if(nextnode):
        #         nextnode['prev'] = self.cur['prev']
        #     self.cur = prevnode
        # else:
        #     self.cur = nextnode
        return self.cur


def solve():
    n = ria()[0]

    for tt in range(n):
        ins = list(rsa()[0])
        # it(ins)
        li = dictlist()
        curlen = 0
        pos = 0

        for i, cur in enumerate(ins):
            if(cur == '<'):
                li.movePrev()
                pass
            elif(cur == '>'):
                li.moveNext()
                pass
            elif(cur == '-'):
                li.remove()
                pass
            else:
                li.add(cur)
                pass
        # li.printList()
        lis = li.getList()
        print(''.join(lis))
    pass


solve()
# import profile
# profile.run("solve()")
