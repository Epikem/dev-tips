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

def create2dArray(x,y,val=False):
    arr = [val]*y
    for yy in range(y):
        if(x == 0):
            arr[yy] = []
        else: arr[yy] = [val]*x
    return arr

from sys import stdin
input=stdin.readline
import copy
# import queue
from collections import deque

# from itertools import permutations
sys.setrecursionlimit(1000)

def solve():
    dx=[-1,0,1,0]
    dy=[0,-1,0,1]
    lastgroup=1
    r,c=ria()
    groupOf=create2dArray(c,r, 0)
    groupToCells={}
    maps=create2dArray(c,r, 0)
    visited=create2dArray(c,r, False)
    lgroups=[]
    lpoints=[]
    meltQ = deque()
    nextMeltQ=deque()
    mergedGroup={0:0}

    def printMap():
        for row in range(r):
            it(*maps[row])
    def printGroupMap():
        for row in range(r):
            it(*groupOf[row])
    def getMergedGroup(g):
        lg = mergedGroup[g]
        gg = mergedGroup[mergedGroup[g]]
        while(lg!=gg):
            mergedGroup[lg]=gg
            lg=gg
            gg=mergedGroup[lg]
        mergedGroup[g]=gg
        return gg

    def getGroup(y,x):
        if(y<0 or y>=r or x<0 or x>=c):
            return -1
        g = groupOf[y][x]
        return getMergedGroup(g)
    def setGroup(y,x,g):
        groupOf[y][x]=g
    def melt(nextMeltQ):
        count = 0
        # it(nextMeltQ)
        # nextMeltQ=deque()
        # nextMeltQ.append(0)
        melted=create2dArray(c,r,False)
        while(len(nextMeltQ) != 0):
            # it('melting', len(nextMeltQ))
            
            # check if two swans met
            meltQ=nextMeltQ
            nextMeltQ=deque()
            # it('')
            # printGroupMap()

            (lp1y,lp1x)=lpoints[0]
            (lp2y,lp2x)=lpoints[1]
            # it('groupOf[lp1y][lp1x],groupOf[lp2y][lp2x]',getGroup(lp1y,lp1x),getGroup(lp2y,lp2x))
            
            if(getGroup(lp1y,lp1x)==getGroup(lp2y,lp2x)):
                return count
            while(len(meltQ) != 0):
                
                # melt outer ice
                (ny,nx,g) = meltQ.popleft()
                # melt current position
                # setGroup(ny,nx,g)
                if(melted[ny][nx]):
                    continue
                melted[ny][nx]=True
                groupOf[ny][nx]=g
                maps[ny][nx]='.'
                nearGroups=set()
                for i in range(4):
                    py,px=ny+dy[i],nx+dx[i]
                    if(py<0 or py>=r or px<0 or px>=c):
                        continue
                    pg = getGroup(py,px)
                    if(pg>0):
                        nearGroups.add(pg)
                    elif(pg==0):
                        # it('putting next.', py,px,g)
                        nextMeltQ.append((py,px,g))

                # merge all near water groups
                # it('nearGroups',nearGroups)
                ali = list(nearGroups)
                for i in range(len(ali)-1):
                    if(getMergedGroup(ali[i])!=getMergedGroup(ali[i+1])):
                        mergeGroups(ali[i],ali[i+1])
            count+=1
            pass
            # printMap()
        return count

    def mergeGroups(g1,g2):
        if(g1>g2):
            g1,g2=g2,g1
        mergedGroup[getMergedGroup(g2)]=getMergedGroup(g1)
        
    def putNewCellToGroup(g, v):
        if(g in groupToCells):
            groupToCells[g].append(v)
        else:
            groupToCells[g] = [v]

    def checkBoundary(y,x):
        if(y<0 or y>=r or x<0 or x>=c):
            return False
        else:return True

    for wy in range(r):
        maps[wy]=list(rsa()[0])
    # it(maps)
    for wx in range(c):
        for wy in range(r):
            if(visited[wy][wx]):
                continue
            # visited[wy][wx]=True
            v=maps[wy][wx]
            if(v=='X'):
                groupOf[wy][wx]=0
                continue

            q = deque()
            groupOf[wy][wx]=lastgroup
            mergedGroup[lastgroup]=lastgroup

            q.append((wy,wx,lastgroup))

            while(len(q) != 0):
                (y,x,g) = q.popleft()
                if(visited[y][x]):
                    continue
                visited[y][x]=True
                v= maps[y][x]
                if(v=='X'):
                    groupOf[y][x]=0
                else:
                    if(v=='L'):
                        lpoints.append((wy,wx))
                    groupOf[y][x]=lastgroup
                    mergedGroup[lastgroup]=lastgroup

                    for i in range(4):
                        py,px=y+dy[i],x+dx[i]
                        if(checkBoundary(py,px)):
                            q.append((py,px,lastgroup))

            lastgroup+=1
    for x in range(c):
        for y in range(r):
            if(maps[y][x]=='X'):
                groupOf[y][x]=0
                waterGroup=0
                for i in range(4):
                    if(checkBoundary(y+dy[i],x+dx[i])):
                        if(maps[y+dy[i]][x+dx[i]]!='X'):
                            waterGroup=groupOf[y+dy[i]][x+dx[i]]
                if(waterGroup>0):
                    meltQ.append((y,x, waterGroup))

    print(melt(meltQ))

    pass

solve()
# import profile
# profile.run("solve()")