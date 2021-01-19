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
def solve():
    def checkSolved(state):
        solved = True
        alen = len(state['A'])
        blen=len(state['B'])
        clen=len(state['C'])
        for i in range(alen):
            if(state['A'][i] != 'A'):
                solved=False
        for i in range(blen):
            if(state['B'][i] != 'B'): solved=False
        for i in range(clen):
            if(state['C'][i] != 'C'): solved=False
        return solved

    def search(state):


        pass

    def moveOne(state, a,b):
        # move one from top of a to top of b
        if(len(state[a])==0):
            return None
        nextState = copy.deepcopy(state)
        nextState[b].append(nextState[a][-1])
        nextState[a].pop()
        nextState['count']+=1
        return nextState

    a,st=[0,'']
    initialState={}
    lastState={'A':[],'B':[],'C':[], 'count':0}
    colmap = ['A','B','C']
    counts={'A':0,'B':0,'C':0}
    for i in range(3):
        ins = ris()
        a,st=ins if len(ins)==2 else [0,'']
        a,st=int(a),str(st)
        st = list(st)
        for s in st:
            counts[s]+=1
            lastState[s].append(s)
        initialState[colmap[i]]=st
    # it(counts)
    # it('initialState',initialState)
    
    # it('lastState',lastState)
    initialState['count']=0
    # it('initialState',initialState)
    
    q.put(initialState)
    cost = 9999999999
    cnt=0
    rq = queue.Queue()
    rq.put(lastState)
    rdic={}
    rdepth = 0
    passed = False
    stepped1=False
    stepped2=False
    while(not passed and (not q.empty() or not rq.empty())):
        stepped1=False
        while(not stepped1):
            n = q.get()
            if(n is None): continue
            key = str(n['A'])+str(n['B'])+str(n['C'])
            
            if(key in dic and n['count']>=dic[key]):
                # cnt+=1
                # it('cnt',cnt)
                # it(n['count'])
                continue
            else:
                # it('new record', len(dic.keys()), n['count'])
                dic[key] = n['count']
            
            # it('n',n)
            
            if(checkSolved(n)):
                cost = n['count']
                passed = True
                break
            if(key in rdic and rdic[key]<rdepth):
                # it('bidirectional search success')
                
                cost = n['count']+rdic[key]
                passed=True
                break
            q.put(moveOne(n, 'A', 'B'))
            q.put(moveOne(n, 'A', 'C'))
            q.put(moveOne(n, 'B', 'A'))
            q.put(moveOne(n, 'B', 'C'))
            q.put(moveOne(n, 'C', 'A'))
            q.put(moveOne(n, 'C', 'B'))
            stepped1=True

        stepped2=False
        while(not stepped2):
            rn = rq.get()
            if(rn is None): continue
            rkey = str(rn['A'])+str(rn['B'])+str(rn['C'])
            if(rkey in rdic and rn['count']>=rdic[rkey]):
                continue
            else:
                rdic[rkey]=rn['count']
            
            # if(key in dic.keys()):
            #     cost = rn['count']+dic[key]
            #     break
            
            rq.put(moveOne(rn, 'A', 'B'))
            rq.put(moveOne(rn, 'A', 'C'))
            rq.put(moveOne(rn, 'B', 'A'))
            rq.put(moveOne(rn, 'B', 'C'))
            rq.put(moveOne(rn, 'C', 'A'))
            rq.put(moveOne(rn, 'C', 'B'))

            if(rn['count']>rdepth+1):
                rdepth=rn['count']-1
        
            # if(cnt%100==0):
            #     it('cnt',cnt, n['count'], rn['count'], key)
            #     # it(key in rdic.keys())
            #     it(key)
            #     it(rkey)
            # cnt+=1
            stepped2=True


    print(cost)
    
    pass

solve()