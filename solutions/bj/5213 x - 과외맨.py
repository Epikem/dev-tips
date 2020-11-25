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

def print2DArray(array):
    for r in range(len(array)):
        it(*array[r])

from sys import stdin
input=stdin.readline
import copy
# import queue
from collections import deque

# from itertools import permutations
sys.setrecursionlimit(1000)

def solve():
    n=ria()[0]
    dx=[+1,-1,0,0]
    dy=[0,0,+1,-1]
    visited=create2DArray(n+2,2*n+1+2,False)
    maps=create2DArray(n+2,2*n+1+2,0)
    parents=[0]*(n*n-n//2+2)
    rowno=1
    colno=1
    for i in range(n*n-n//2):
        a,b=ria()
        maps[rowno][colno]=(a,rowno,colno,i+1)
        maps[rowno][colno+1]=(b,rowno,colno+1,i+1)
        colno+=2
        if(rowno%2==1 and colno>2*n):
            rowno+=1
            colno=1
        elif(rowno%2==0 and colno>2*n-2):
            rowno+=1
            colno=1
        
    # print2DArray(maps)
         

    q=deque()
    q.appendleft(maps[1][1])
    visited[1][1]=True
    # visited[1][2]=True
    cost=0
    maxtile=0
    while(len(q)!=0):
        nextp=q.pop()
        (k,r,c,num)=nextp
        # it('num',num)
        if(num>maxtile):
            maxtile=num

        ddx=-1 if r%2==1 else +1
        cost+=1
        for i in range(4):
            nx=c+(dx[i]+ddx if dx[i]==0 else dx[i])
            ny=r+dy[i]

            if(ny>=1 and ny<=n and nx>=1 and nx<=2*n):
                newitem=maps[ny][nx]
                if(newitem==0):
                    continue
                (nk,nr,nc,nn)=newitem
                # it('visiting ny nx',ny,nx,newitem)
                if(not visited[nr][nc]):
                    # it(k,nk,num,nn)
                    if((k==nk) or num==nn):
                        # it('visiting ny nx',newitem)
                        visited[nr][nc]=True
                        nextitem=maps[ny][nx]
                        if(num!=nn):
                            parents[nn]=(num)
                            q.appendleft(nextitem)
                        else:
                            q.append(nextitem)
        pass
    
    nn=maxtile
    li=deque()
    li.appendleft(nn)
    while(True):
        (nn)=parents[nn]
        if(nn==0):
            break
        li.appendleft(nn)
    print(len(li))
    print(*li)
    return


    pass

solve()
# import profile
# profile.run("solve()")