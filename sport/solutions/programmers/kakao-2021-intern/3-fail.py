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
from random import betavariate, randint
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


def genNums(n, maxv):
    import random
    arr = []
    for i in range(n):
        arr.append(random.randint
                   (0, maxv))
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

def is_int(num):
    try:
        int(num)
        return True
    except:
        return False
    
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



def solve(n,k,cmd):
    # print(n,k,cmd)

    # U, D 이동
    # C 삭제, 다음 행 또는 마지막 행이면 이전 행 선택
    # Z 가장 최근 삭제 복구, 선택 행은 보존

    # 리턴: 각 행별 삭제 여부 OX 표시 문자열

    # 제한:
    # n ~ 100만
    # cmd ~ 20만

    # 다음 행, 이전 행에 대한 정보 및 현재 선택 행에 대한 정보가 필요

    # 효율적으로 이동하려면, C로 삭제를 할 때 위아래를 연결시켜야 하는데, 
    # 그러면 다시 복구할때 복잡해진다.

    # 또, 복구할 때 진짜 어려운 것은 커서를 어떻게 관리하느냐다.
    # 삭제시에는 커서를 직접 옮겨주는데,
    # 복구시에는 그대로 두면 되나??

    table = {}
    cursor = k+1
    
    for i in range(1, n+1):
        # prev, next, alive
        newr = [i-1 if i != 1 else -1, i+1 if i != n else -1, 1]
        table[i] = newr

    # print('table', table, 'cursor', cursor)
    
    def move(direction, amount):
        nonlocal cursor
        if(amount <= 0):
            return

        if(direction == 'U'):
            next_cursor = table[cursor][0]
        else:
            next_cursor = table[cursor][1]
        if(next_cursor != -1):
            cursor = next_cursor
        amount-=1
        move(direction, amount)
        
        pass

    def remove():
        nonlocal cursor
        cur = table[cursor]
        prev_cur = cursor
        my_prev, my_next, val = cur
        nextc = cur[1]

        cur[2] = 0

        # link prev's next to my next
        if(my_prev != -1):
            table[my_prev][1] = my_next

        # link next's prev to my prev
        if(my_next != -1):
            table[my_next][0] = my_prev
        
        if(nextc != -1):
            cursor = nextc
        else:
            cursor = cur[0]
        
        return prev_cur

    def recover(target):
        # nonlocal cursor

        # recover
        cur = table[target]
        cur[2] = 1
        my_prev, my_next, val = cur

        # recover my prev's next to me
        if(my_prev != -1):
            table[my_prev][1] = target
        
        # recover my next's prev to me
        if(my_next != -1):
            table[my_next][0] = target
        
        pass
    
    stack = []
    for i,cmdstr in enumerate(cmd):
        cmds =  cmdstr.split(' ')
        # print(cmds)
        typ = cmds[0]
        
        if typ == 'C':
            target = remove()
            stack.append(target)
        elif typ == 'Z':
            target = stack.pop()
            # print('target',target)
            recover(target)
        else:
            move(cmds[0], int(cmds[1]))
        
        # print('table', table, 'cursor', cursor)
        # print(''.join([str('C' if x == cursor else ('O' if table[x][2] == 1 else 'X')) for x in table]))
    ans = ''.join([str('O' if table[x][2] == 1 else 'X') for x in table])
    return ans

solution = solve

n,k,cmd,result = 8,2, ["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"],"OOXOXOOO"

ans = solve(n,k,cmd)

# # # debug
# print(ans, "==", result)
assert(ans == result)


