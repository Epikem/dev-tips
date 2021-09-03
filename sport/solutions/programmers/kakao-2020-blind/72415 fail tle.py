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

def solution(board, r, c):
    from collections import defaultdict, deque
    from itertools import permutations
    
    # print(board, r, c)
    card_cnt = 0
    # cards = defaultdict(list)
    cards = {}
    for row in range(4):
        for col in range(4):
            v = board[row][col]
            if(v != 0):
                # cards[v].append((row, col))
                cards[card_cnt] = (v, row, col)
                card_cnt += 1
            
    # print(cards)

    # create permutation of !card_cnt
    perm = permutations(range(card_cnt))

    dr = [0, 0, 1, -1]
    dc = [1, -1, 0, 0]
    # down, up, right, left

    # move with ctrl: move towards direction until meet bound or another card 
    def moveCtrl(dir, cr, cc):
        drr = dr[dir]
        dcc = dc[dir]
        # check if next direction pos is another card on board or out of bound
        nr = cr + drr
        nc = cc + dcc
        if(nr < 0 or nr >= 4 or nc < 0 or nc >= 4):
            return (cr, cc)
        if(board[nr][nc] != 0):
            return (nr, nc)
        return moveCtrl(dir, nr, nc)

    best_cost = 9999999
    for p in perm:
        cur_cost = 0
        cur_row = r
        cur_col = c
        last_card = -1
        fail = False
        removed = []
        for card in p:
            next_card = cards[card]
            if(last_card != -1):
                if(last_card != next_card[0]):
                    fail = True
                    break
                else:
                    last_card = -1
            else:
                last_card = next_card[0]
            # print((cur_row, cur_col), ' -> ', next_card)

            removed.append(next_card)
            board[cur_row][cur_col] = 0
            # run djikstra
            dist = create2DArray(4, 4, 9999999)
            dist[cur_row][cur_col] = 0
            q = deque()
            q.append((cur_row, cur_col))
            
            while(len(q) > 0):
                cur_row, cur_col = q.popleft()
                for d in range(4):
                    nr = cur_row + dr[d]
                    nc = cur_col + dc[d]
                    if(nr < 0 or nr >= 4 or nc < 0 or nc >= 4):
                        continue
                    if(dist[nr][nc] > dist[cur_row][cur_col] + 1):
                        dist[nr][nc] = dist[cur_row][cur_col] + 1
                        q.append((nr, nc))
                    (crr,ccc) = moveCtrl(d, cur_row, cur_col)
                    if(dist[crr][ccc] > dist[cur_row][cur_col] + 1):
                        dist[crr][ccc] = dist[cur_row][cur_col] + 1
                        q.append((crr, ccc))

            cur_row = next_card[1]
            cur_col = next_card[2]
            cur_cost += dist[cur_row][cur_col] # enter
            
            # print('dist', dist, 'cost', cur_cost)

        # restore board
        for card in removed:
            board[card[1]][card[2]] = card[0]

        if(not fail):
            # print('perm', p, 'cost', cur_cost)
            best_cost = min(best_cost, cur_cost)

    # print('best', best_cost+6)
    
    return best_cost + card_cnt

board,r,c,result = [[1,0,0,3],[2,0,0,0],[0,0,0,2],[3,0,1,0]],1,0,14

ans = solution(board, r, c)

# # debug
# print(ans, "==", result)
# assert(ans == result)


