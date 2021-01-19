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
import queue
# from collections import

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
    meltQ = queue.Queue()
    nextMeltQ=queue.Queue()
    mergedGroup={0:0}

    def printMap():
        for row in range(r):
            it(*maps[row])
    def printGroupMap():
        for row in range(r):
            it(*groupOf[row])
    def getGroup(y,x):
        if(y<0 or y>=r or x<0 or x>=c):
            return -1
        g = groupOf[y][x]
        lg = mergedGroup[g]
        gg = mergedGroup[mergedGroup[g]]
        while(lg!=gg):
            lg=gg
            gg=mergedGroup[lg]
        mergedGroup[g]=gg
        return gg
        # return mergedGroup[groupOf[y][x]]
    def setGroup(y,x,g):
        groupOf[y][x]=g
    def melt(meltQ):
        count = 0
        nextMeltQ=queue.Queue()
        nextMeltQ.put(0)
        while(not nextMeltQ.empty()):
            it('melting', nextMeltQ.qsize())
            # check if two swans met
            nextMeltQ=queue.Queue()
            # it('')
            # printGroupMap()

            (lp1y,lp1x)=lpoints[0]
            (lp2y,lp2x)=lpoints[1]
            # it('groupOf[lp1y][lp1x],groupOf[lp2y][lp2x]',getGroup(lp1y,lp1x),getGroup(lp2y,lp2x))
            
            if(getGroup(lp1y,lp1x)==getGroup(lp2y,lp2x)):
                return count
            while(not meltQ.empty()):
                
                # melt outer ice
                (ny,nx,g) = meltQ.get()
                # melt current position
                setGroup(ny,nx,g)
                # putNewCellToGroup(g, (ny,nx))
                maps[ny][nx]='.'
                groupCount=0
                for i in range(4):
                    py,px=ny+dy[i],nx+dx[i]
                    if(py<0 or py>=r or px<0 or px>=c):
                        continue
                    pg = getGroup(py,px)
                    if(pg>0):
                        groupCount+=1
                    elif(pg==0):
                        # it('putting next.', py,px,g)
                        nextMeltQ.put((py,px,g))
                if(groupCount>=2):
                    nearGroups=set()
                    for i in range(4):
                        py,px=ny+dy[i],nx+dx[i]
                        if(py<0 or py>=r or px<0 or px>=c):
                            continue
                        pg = getGroup(py,px)
                        if(pg>0):
                            nearGroups.add(pg)

                    # merge all near water groups
                    # it('nearGroups',nearGroups)
                    ali = list(nearGroups)
                    for i in range(len(ali)-1):
                        if(mergedGroup[ali[i]]!=mergedGroup[ali[i+1]]):
                            # it('merging groups: ',ali[i], ali[i+1])
                            mergeGroups(ali[i],ali[i+1])
            count+=1
            meltQ=nextMeltQ
            pass
        pass

    def mergeGroups(g1,g2):
        if(g1>g2):
            g1,g2=g2,g1
        mergedGroup[g2]=mergedGroup[g1]
        
    def putNewCellToGroup(g, v):
        if(g in groupToCells):
            groupToCells[g].append(v)
        else:
            groupToCells[g] = [v]

    def checkBoundary(y,x):
        if(y<0 or y>=r or x<0 or x>=c):
            return False
        else:return True

    # def dfs(y,x,g):
    #     if(y<0 or y>=r or x<0 or x>=c):
    #         return g
    #     if(visited[y][x]):
    #         return g
    #     visited[y][x]=True
    #     v = maps[y][x]
    #     if(v=='.' or v=='L'):
    #         if(v=='L'):
    #             lgroups.append(g)
    #             lpoints.append((y,x))
    #         groupOf[y][x]=g
    #         putNewCellToGroup(g,(y,x))
    #         mergedGroup[g]=g
    #         for i in range(4):
    #             dfs(y+dy[i],x+dx[i],g)
    #         return g+1
    #     elif(v=='X'):
    #         groupOf[y][x]=0
    #         return g

    
    for wy in range(r):
        maps[wy]=list(rsa()[0])
    # it(maps)
    for wx in range(c):
        for wy in range(r):
            if(visited[wy][wx]):
                continue
            visited[wy][wx]=True
            v=maps[wy][wx]
            if(v=='X'):
                groupOf[wy][wx]=0
                continue
            if(v=='L'):
                lpoints.append((wy,wx))

            q = queue.Queue()
            groupOf[wy][wx]=lastgroup
            mergedGroup[lastgroup]=lastgroup
            q.put((wy,wx,lastgroup))

            while(not q.empty()):
                y,x,g = q.get()
                if(visited[y][x]):
                    continue
                visited[y][x]=True

                for i in range(4):
                    py,px=y+dy[i],x+dx[i]
                    if(checkBoundary(py,px)):
                        q.put(py,px,lastgroup)


            # lastgroup=dfs(wy,wx,lastgroup)
            lastgroup+=1
    for x in range(c):
        for y in range(r):
            if(maps[y][x]=='X'):
                groupOf[y][x]=0
                waterGroup=0
                for i in range(4):
                    if(checkBoundary(y+dy[i],x+dx[i])):
                        if(maps[y+dy[i]][x+dx[i]]=='.'):
                            waterGroup=groupOf[y+dy[i]][x+dx[i]]
                if(waterGroup>0):
                    meltQ.put((y,x, waterGroup))

    # it(groupOf)
    # it('start melting!!!@@@@')
    # it(lgroups)
    print(melt(meltQ))

    pass

# solve()
import profile
profile.run("solve()")