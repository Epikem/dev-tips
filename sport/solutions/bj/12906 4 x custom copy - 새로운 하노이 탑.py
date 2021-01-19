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

def ris():
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

# from itertools import permutations

q = queue.Queue()
dic = {}
keyset = set()

def solve():
    def getStateCopy(state):
        newState = {}
        for i in range(3):
            newState[colmap[i]]=state[colmap[i]][:]
        newState['count']=state['count']
        # it('newState',newState)
        
        return newState
    def checkSolved(state):
        solved = True
        alen = len(state['A'])
        blen=len(state['B'])
        clen=len(state['C'])
        a = state['A']
        b=state['B']
        c=state['C']
        for i in range(alen):
            if(a[i] != 'A'):
                solved=False
        for i in range(blen):
            if(b[i] != 'B'): solved=False
        for i in range(clen):
            if(c[i] != 'C'): solved=False
        return solved

    def search(state):


        pass

    def moveOne(state, a,b):
        # move one from top of a to top of b
        if(len(state[a])==0):
            return None
        nextState = getStateCopy(state)
        nextState[b].append(nextState[a][-1])
        nextState[a].pop()
        nextState['count']+=1
        return nextState

    a,st=[0,'']
    initialState={}
    colmap = ['A','B','C']
    counts={'A':0,'B':0,'C':0}
    for i in range(3):
        ins = ris()
        a,st=ins if len(ins)==2 else [0,'']
        a,st=int(a),str(st)
        st = list(st)
        initialState[colmap[i]]=st
    # it(counts)
    # it('initialState',initialState)
    
    # it('lastState',lastState)
    initialState['count']=0
    # it('initialState',initialState)
    
    q.put(initialState)
    cost = 9999999999
    cnt=0

    while(not q.empty()):
        n = q.get()
        if(n is None): continue
        key = str(n['A'])+str(n['B'])+str(n['C'])
        # key = str(n)
        if(key in keyset):
            # cnt+=1
            # it('cnt',cnt)
            # it(n['count'])
            continue
        else:
            # it('new record', len(dic.keys()), n['count'])
            dic[key] = n['count']
            keyset.add(key)
        
        # it('n',n)
        
        if(checkSolved(n)):
            cost = n['count']
            passed = True
            break
        
        li=[]
        li.append(moveOne(n, 'A', 'B'))
        li.append(moveOne(n, 'A', 'C'))
        li.append(moveOne(n, 'B', 'A'))
        li.append(moveOne(n, 'B', 'C'))
        li.append(moveOne(n, 'C', 'A'))
        li.append(moveOne(n, 'C', 'B'))

        for item in li:
            if(item is not None):
                q.put(item)
        
        # q.put(moveOne(n, 'A', 'C'))
        # q.put(moveOne(n, 'B', 'A'))
        # q.put(moveOne(n, 'B', 'C'))
        # q.put(moveOne(n, 'C', 'A'))
        # q.put(moveOne(n, 'C', 'B'))


    print(cost)
    
    pass

solve()