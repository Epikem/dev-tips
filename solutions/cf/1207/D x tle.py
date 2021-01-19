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

    pass


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

MOD=998244353
facdic={}
def fac(n):
    if(n in facdic):
        return facdic[n]
    ret=0
    if(n==1):
        ret=1
    else:
        ret=n%MOD*fac(n-1)%MOD
    facdic[n]=ret
    return ret

def solve():
    n = ria()[0]
    dic1={}
    dic2={}
    val=0
    for nn in range(n):
        s=ria()
        tmp=1
        # n range is large. 30,0000 so cant permutate all
        a,b=s
        dic1[a]=[] if a not in dic1 else dic1[a]
        dic2[b]=[] if b not in dic2 else dic2[b]
        dic1[a].append([a,b])
        dic2[b].append([a,b])    
        pass
    total=[]
    tmp=1
    for i in dic1.keys():
        tmp*=fac(len(dic1[i]))
        total+=sorted(dic1[i], key=lambda x:x[1])
    # it('total',total)
    prev=(-1,-1)
    totalval=1
    totaltmp=1
    for t in total:
        if(t==prev):
            totaltmp+=1
        else:
            if(t[1]<prev[1]):
                totalval=0
                break
            prev=t
            totalval*=fac(totaltmp)
            totaltmp=1
    totalval*=fac(totaltmp)

    # it('totalval',totalval)
    
    val+=tmp
    # it(tmp)
    tmp=1
    for i in dic2.keys():
        tmp*=fac(len(dic2[i]))
    val+=tmp
    # it(tmp)
    # it('val',val)
    ans=(fac(n)-val)%MOD+totalval%MOD
    ans=ans if ans>0 else ans+MOD
    print(ans%MOD)


    pass

solve()
# import profile
# profile.run("solve()")