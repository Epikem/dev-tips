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


dy = [1, 0, 0, -1]
dx = [0, 1, -1, 0]


def solve():

    # 판다가 처음에 어디서 출발할 지 모르므로 상당히어렵다.
    # 맵크기가 최대 500x500=250000이므로 무턱대고
    # 복사할 수도 없다.
    # 원본 맵과, 각 위치에서 시작했을 때 최대 생존일수를 담은 맵을 유지한다면?
    # 그러면 과거 원본 맵중에 어디어디를 먹었는지 모르게 된다.
    # 그걸 셀마다 배열로 저장한다면 메모리를 너무 많이 먹게 된다.
    # 왜 하필 최대 크기가 1백만일까?
    # ...
    # 주변에서 생존 일수 정보를 합치려면 데이터를 어떻게 저장해야 할까??

    # 일단 처음에는 모든 위치에서 1일 것.
    # 그 다음은, 이전과 비교하여 전보다 원본이 높은 쪽 기준으로 더해나간다.
    # 문제는, 역시 이 누적이 원본 맵중에 어디어디를 먹었던 것인지 알 수 없는것,
    # 근데, 그게 꼭 필요한가? 최종 상태만 안다면, 최종 누적과 마지막으로 먹었던 양만 각 셀이 기록해 둔다면 충분할지도??
    # 1차원으로 생각해보자. 임의 위치에서 시작해서 돌아다닐 때,
    # 점점 커지는 쪽으로 움직여야 할 때 최대 길이는 얼마인가를 구하는
    # 문제이다.
    #

    n = ria()[0]

    maps = create2DArray(n, n, 0)
    vals = create2DArray(n, n, 0)
    cells = []
    for r in range(n):
        ins = ria()
        for c in range(n):
            this = ins[c]
            cells.append([this, r, c])
            maps[r][c] = this

    # it(maps)
    cells.sort()
    # it(cells)

    # 근데 이거.. 대나무의 양이 의미가 있나? 어차피 상하좌우로
    # 늘어나는 방향으로만 움직이는 그래프 또는 트리 형태가 될 텐데
    # 그러면 위상 정렬을 해서 가장 긴 경로를 찾으면 되지 않나?
    # 근데 그 정렬상태에서 긴 경로를 어떻게 찾을지도 문제다.
    # 플로이드 워셜처럼 전체 노드에 대해 주변에서 누적을 반복
    # 하게 한다면, 맵 크기 25000*최대길이 25000이므로 무조건
    # 시간초과다.
    # 그렇다면, 가장 작은 셀부터 위치를 기록해놓고 주변에서 더하면서
    # 초기화한다면? 25000개를 정렬해야 하는데, 그건 가능할 듯하고,

    def boundCheck(cr, cc, mr, mc):
        if(cc < 0 or cr < 0 or cc >= mc or cr >= mr):
            return False
        return True

    def getMaxv(rr, cc):
        maxv = 1
        for i in range(4):
            nr, nc = rr+dy[i], cc+dx[i]
            if(not boundCheck(nr, nc, n, n)):
                continue
            # 주변에 원본이 여기보다 작은데 누적수가 큰 셀이 있다면 그것 +1 을 가지고, 없다면 값 1을 가진다.
            if(vals[nr][nc]+1 > maxv and maps[nr][nc] < maps[rr][cc]):
                maxv = vals[nr][nc]+1
        return maxv
    totalMax = -1
    for i, v in enumerate(cells):
        # it(v)
        val, r, c = v
        vals[r][c] = getMaxv(r, c)
        totalMax = max(totalMax, vals[r][c])
    # it(vals)
    print(totalMax)
    pass


solve()
# import profile
# profile.run("solve()")
