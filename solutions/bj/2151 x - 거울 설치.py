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

def rsa():
    return list(map(str, input().strip('\n').split(' ')))

# def create2dArray(y,x,val=False):
#     arr = [val]*x
#     for xx in range(x):
#         if(y == 0):
#             arr[xx] = []
#         else: arr[xx] = [val]*y
#     return arr

def create2DArray(rows,cols,val=False):
    return [[val for c in range(cols)] for r in range(rows)]

def create3DArray(zs,ys,xs,val=False):
    return [[[val for x in range(xs)] for y in range(ys)] for z in range(zs)]

def print2DArray(array):
    for r in range(len(array)):
        it(*array[r])

from sys import stdin
input=stdin.readline
import copy
# import queue
from collections import deque

# from itertools import permutations
sys.setrecursionlimit(10000)

# https://www.acmicpc.net/problem/2151

def solve():
    n = ria()[0]
    mapper={'*':-1,'.':0,'#':2,'!':1}
    maps=create2DArray(n,n,-1)
    doors=[]
    costs=create2DArray(n,n,999999)
    mirrors={}  #mirros[k]-> k번째에 찾아지는 거울들
    foundMirrors={} # foundMirrors[d] = d번 거울을 찾았는지 여부
    dirs={}
    dx=[0,0,1,-1]
    dy=[1,-1,0,0]
    # /:
    # (1,0) (0, -1)
    # (0, 1) (-1, 0)
    # (0, -1) (1, 0)
    # (-1, 0) (0, 1)

    # \:
    # (0, 1) (1, 0)
    # (-1, 0) (0, -1)
    # (1, 0) (0, +1)
    # (0, -1) (-1, 0)
    def tryAll(level):
        left = len(mirrors[level])
        tryMirror(level,0,left,0)
    def tryMirror(level,chosen,left,used):
        if(chosen==left):
            search(doors[0],startDir,used)
            return

        it('trying')
        maps[y][x]=0
        tryMirror(level,chosen+1,left,used)      

        it('trying')
        maps[y][x]=3
        tryMirror(level,chosen+1,left,used+1)

        it('trying')
        maps[y][x]=4
        tryMirror(level,chosen+1,left,used+1)

        # install 1 direction
        # search()...
        # install 2 direction
        # search() ...
        # uninstall 
        # search()
        pass
    def search(pos,direction,k):
        y,x=pos
        it('searching', pos, direction, k)
        if(maps[y][x]==1):
            it(mirrors)
            if(not pos in foundMirrors):
                it('FOUND MIRROr', pos, k)
                foundMirrors[pos]=1
                if(not k+1 in mirrors):
                    mirrors[k+1]=[]
                mirrors[k+1].append(pos)
        dy,dx=direction
        ny,nx=y+dy,x+dx
        ch = maps[ny][nx]
        if(ch==-1): return
        elif(ch==2):
            if(pos==goal):
                start=goal
                print(k)
                print(k)
                print(k)
                print(k)
                print(k)
                print(k)
                print(k)
                print(k)
                print(k)
                print(k)
                print(k)
                print(k)
                print(k)
                print(k)
                return
        elif(ch==0 or ch==1):
            search((ny,nx),direction,k)
        elif(ch==3 or ch==4):
            if(ch==3):
                dy,dx=-dx,-dy
            else:
                dy,dx=dx,dy
            direction=(dy,dx)

            search((ny,nx),direction,k)
        pass
    for i in range(n):
        maps[i] = [mapper[j] for j in list(rsa()[0])]
        it(maps[i])

    for y in range(n):
        for x in range(n):
            if(maps[y][x]==2):
                doors.append((y,x))

    it(doors)

    start = doors[0]
    goal=doors[1]
    startDir=(0,0)
    for i in range(4):
        ch=maps[start[0]+dy[i]][start[1]+dx[i]]
        it(ch)
        if(ch==0 or ch==1):
            startDir=(dy[i],dx[i])
    level=1
    search(start,startDir,0)
    while(start!=goal):
        if(level not in mirrors):
            mirrors[level]=[]
        left = len(mirrors[level])
        tryMirror(level,0,left,0)
        level+=1
        pass
    pass

solve()
# import profile
# profile.run("solve()")