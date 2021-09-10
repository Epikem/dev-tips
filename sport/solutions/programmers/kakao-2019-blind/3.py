# -*- coding: utf-8 -*-
#!/usr/bin/python

# 풀이는 `solve()` 함수에 있습니다.
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

from operator import add
from collections import defaultdict
from random import betavariate
from sys import stdin
from collections import deque
import copy
false = False
true = True
null = None
# import math
TEST = False
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


def numToBits(num):
    from collections import deque
    bits = deque()
    while(num > 0):
        bits.appendleft(num % 2)
        num = num//2
    return bits


def numToBin(num):
    return bin(num)


def bitsToNum(bits):
    ret = 0
    for i, v in enumerate(reversed(bits)):
        ret += 2 ** (i) if v == 1 else 0
    return ret
    
class dotdict(dict):
    """dot.notation access to dictionary attributes"""
    __getattr__ = dict.get
    __setattr__ = dict.__setitem__
    __delattr__ = dict.__delitem__

def binToNum(binary: str):
    return int(binary, 2)

def getDigitCnt10(num):
    return len(str(num))

def getBitCnt(num):
    return len(bin(num)) - 2

class point2d:
    def __init__(self, r, c):
        self.r = r
        self.c = c
    
    def __str__(self):
        return 'point2d({}, {})'.format(self.r, self.c)

    def to_idx(self, mr, mc = 99999999):
        if(self.r<0 or self.c<0 or self.r>=mr or self.c>=mc):
            return -1
        return self.r * mr + self.c
    
    def from_idx(idx, mr, mc = 1):
        p = point2d(idx // mr, idx % mr)
        return p

def solve(relation):
    # 모든 조합에 대한 카운트를 만들어서, 카운트를 세서, 그 카운트가 전체카운트와 같은지 확인
    # 다르게 생각하면, 해당 조합에 대해 테스트할 때 단 하나라도 중복이 존재하면 그 조합은 실패이다.
    # 문자열을 이용한 트릭은 안되려나?
    # 
    # 최소성도 해야한다는 걸 못봤다...
    
    # 2^8 - 1가지 조합
    len_rows = len(relation)
    len_cols = len(relation[0])

    # print(len_rows, len_cols)

    from itertools import combinations

    ans = 0
    used_set = []

    for r in range(len_cols):
        comb = list(combinations(range(len_cols), r+1))

        # print(comb)
        
        for combi in list(comb):
            li = []
            dup = False
            
            for _,row in enumerate(relation):
                items = []
                for item in combi:
                    # check intersect set
                    for prev_set in used_set:
                        # print('COMP', set(combi), prev_set)
                        if(set(combi).intersection(prev_set) == prev_set):
                            # print('DUP!!')
                            dup=True
                            break

                    # if item in used_set:
                    #     dup = True
                    #     break
                    
                    items.append(row[item])
                li.append('-'.join(items))

            li.sort()
            
            last = ''
            for _,row in enumerate(li):
                if(last == row):
                    dup = True
                    break
                last = row

            if not dup :
                # print('pass ', combi)
                # print('li', li)
                ans+=1
                used_set.append(set(combi))
            
    # print(ans)
    return ans

solution = solve

# relation,	result = [["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]],	2
relation,result = [["100","ryan","aasd","2"]
,["200","apeach","fdsfsf","2"]
,["300","tube","fefe","3"]
,["400","con","ffwefe","4"]
,["500","asdasd","music","3"],["600","asdasd","music","2"]],	2

ans = solve(relation)

# # # debug
print(ans, "==", result)
assert(ans == result)


