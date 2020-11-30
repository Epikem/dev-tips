false = False
true = True
null = None
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


# def AddImports(libraryNames):
#     for libname in libraryNames:
#         if (type(libname) == type(tuple())):
#             short = libname[1]
#             libname = libname[0]
#         else:
#             short = None
#         try:
#             lib = __import__(libname)
#         except ImportError:
#             pass
#         else:
#             if short:
#                 globals()[short] = lib
#             else:
#                 globals()[libname] = lib
#     return True


# libnames = ['fileinput', 'codecs', 'operator', 'functools', 'math',
#             'io', 'platform', 'collections', 'mmap', 'logging', 'logging.handlers']
# # libnames = ['math']

# AddImports(libnames)
# IntellisenseHint = False
# if IntellisenseHint:
#     import fileinput
#     import codecs
#     import operator
#     import functools
#     import math
#     import io
#     import platform
#     import collections
#     import mmap
#     import logging
#     import logging.handlers
#     # import defs


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


def it(args):
    if(TEST):
        print(args)
    # print(args, vargs)


def floatEqual(a, b):
    diff = math.fabs(a-b)
    if(diff < 1e-10):
        return True
    else:
        return diff <= 1e-8 * max(math.fabs(a), math.fabs(b))


def ria():
    return list(map(int, input().strip(' ').split(' ')))


def solve():
    searchState = {}
    [N, M, H] = ria()
    # 각 가로선들, 넣은 다음 정렬한 후에 적용할 것이다.
    moves = []
    ladders = [0]*(N)
    elms = [0]*(N)
    minPassLevel = 4

    for i in range(len(ladders)):
        ladders[i] = [0]*H
    def printAns(ans):
        if(ans > 3 or ans < 0): print('-1')
        else: print(ans)

    def searchLevel(level):
        nonlocal minPassLevel
        # 레벨 0부터 시작해서 dfs로 하되, 깊이 4 이상이거나, 성공하면 더 깊이 탐색해봐야 의미없으므로 리턴.
        
        if(level >= 4):
            return false
            
        if(check()):
            if(level < minPassLevel):
                minPassLevel = level
            return true
        for n in range(N-1):
            for h in range(H):
                if(putOneLadder(n,h)):
                    [elms[n],elms[n+1]] = [elms[n+1],elms[n]]
                    searchLevel(level+1)
                    # if(searchLevel(level+1)): 
                    #     popOneLadder(n,h)
                    #     [elms[n],elms[n+1]] = [elms[n+1],elms[n]]
                    #     return true
                    # pass
                    popOneLadder(n,h)
                    [elms[n],elms[n+1]] = [elms[n+1],elms[n]]
        return false
    def popOneLadder(n,h):
        ladders[n][h]=0
        return true
    def putOneLadder(n,h):
        # it(['searching ', n, h])
        r = ladders[n+1][h] if n+1 < N else 0
        l = ladders[n-1][h] if n-1 >= 0 else 0
        if(l==1 or r==1 or ladders[n][h] == 1):
            return false
        else:
            ladders[n][h]=1
            return true


    def check():
        ret = true
        
        for i in range(N):
            elms[i]=i
            curn = i
            for h in range(H):
                if(ladders[curn][h] == 1):
                    curn+=1
                elif(ladders[curn-1][h] == 1):
                    curn-=1
            if(curn != i):
                return false
        # if(ladders[2][0] == 1):
        #     it(['checking ', ladders, 'elms: ', elms, ' ans : ', ret])
        return ret
        
    for i in range(N):
        elms[i] = i

    for i in range(M):
        k = ria()
        # it(k)
        moves.append([k[0]-1,k[1]-1])
        ladders[k[1]-1][k[0]-1]=1 ###
        pass
    # it(ladders)
    # it(moves)
    moves.sort(key=lambda x:x[0])
    for i in range(M):
        b = moves[i][1]
        [elms[b],elms[b+1]] = [elms[b+1],elms[b]]
    # it(moves)
    # it(elms)
    searchLevel(0)
    printAns(minPassLevel)

    pass


solve()
