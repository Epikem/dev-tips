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
sys.setrecursionlimit(1000)

def solve():
    # 필요한 연산:
    # 1. 이웃타일 찾기
    # 2. 이웃타일과 인접했는지 확인하기
    # 3. 타일 번호 가져오기
    # 4. 이전 타일 번호 가져오기
    # 
    n=ria()[0]
    graph=create2DArray(n+2,n+2,0)
    adj=[[] for _ in range(n*n-n//2+2)]
    parents=[0 for _ in range(n*n-n//2+2)]
    visited=[False for _ in range(n*n-n//2+2)]
    row=1
    col=1
    for i in range(n*n-n//2):
        a,b=ria()
        graph[row][col]=(a,b,i+1)
        col+=1
        if(row&1==1 and col>n):
            row+=1
            col=1
        elif(row&1==0 and col>n-1):
            row+=1
            col=1
            pass
        pass
    for y in range(1,n+1):
        for x in range(1,n+1):
            item=graph[y][x]
            if(item==0):
                continue
            dx=[-1,+0,+0,+1]+[(-1 if y&1==1 else +1) for _ in range(2)]
            dy=[+0,-1,+1,+0]+[-1,+1]
            for i in range(6):
                ny,nx=y+dy[i],x+dx[i]
                target=graph[ny][nx]
                if(ny<0 or ny>n or nx<0 or nx>n):
                    continue
                if(target==0):
                    continue
                if((y&1==1 and dx[i]==-1) or (y&1==0 and dx[i]!=+1)):
                    if(target[1]==item[0]):
                        adj[item[2]].append(target)
                elif((y&1==1 and dx[i]!=-1) or (y&1==0 and dx[i]==+1)):
                    if(target[0]==item[1]):
                        adj[item[2]].append(target)
    q=deque()
    maxv=-1
    q.append((1,1,1))
    visited[1]=True
    while(len(q)!=0):
        # it('rooping',maxv)
        (r, c, num)=q.popleft()
        maxv=max(maxv,num)
        if(num==n*n-n//2):
            break
        for nextp in adj[num]:
            if(visited[nextp[2]]):
                continue
            visited[nextp[2]]=True
            parents[nextp[2]]=num
            q.append(nextp)

    q=deque()
    cur=maxv
    trail=[maxv]
    while(cur!=0):
        # it('trailing',cur)
        cur=parents[cur]
        trail.append(cur)
    trail.reverse()
    trail=trail[1:]
    print(len(trail))
    print(*trail)

    pass

solve()
# import profile
# profile.run("solve()")