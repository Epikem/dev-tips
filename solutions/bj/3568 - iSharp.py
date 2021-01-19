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

from sys import stdin
input=stdin.readline
import copy
# import queue

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

def rs():
    return input().strip('\n')

def create2dArray(x,y,val=False):
    arr = [val]*y
    for yy in range(y):
        if(x == 0):
            arr[yy] = []
        else: arr[yy] = [val]*x
    return copy.deepcopy(arr)


def solve():
    typeKeys = {'[':'braketStart', ']':'bracketEnd', '&':'reference', '*':'pointer'}
    sep = ','
    def printStmt(parsed):
        [baseTypeName, baseType, names, types] = parsed
        it(parsed)
        for i in range(len(names)):
            reverseTypes = reversed(types[i])

            stmt = baseTypeName + baseType + ''.join(reverseTypes) + ' ' + names[i] + ';'
            print(stmt)
        pass
    def parse(stmt):
        # it('parsing ', stmt)
        index = 0
        length = len(stmt)
        baseTypeName = ''
        baseType = ''
        names = []
        types = []
        lastpos = 0
        while(index < length):
            if(stmt[index] in typeKeys.keys()):

                # it('type : ', stmt[index])
                if(baseTypeName == ''):
                    # End of baseTypeName
                    baseTypeName = stmt[0:index]
                    lastpos = index
                    pass
                else:
                    if(stmt[lastpos] not in typeKeys.keys()):
                        names.append(stmt[lastpos:index])
                        lastpos=index
                pass
            elif(stmt[index] == ' '):
                if(baseType == ''):
                    if(stmt[lastpos] in typeKeys.keys()):
                        baseType = stmt[lastpos : index]
                    if(baseTypeName==''):
                        baseTypeName = stmt[lastpos:index]
                    pass
                lastpos= index+1
                pass
            elif(stmt[index]==',' or stmt[index]==';'):
                if(stmt[lastpos] not in typeKeys.keys()):
                    names.append(stmt[lastpos:index])
                    types.append([''])
                    lastpos=index+2
                else:
                    t = lastpos
                    tl = []
                    while(t<index):
                        if(stmt[t] == '['):
                            tl.append(stmt[t:t+2])
                            t+=1
                        else:
                            tl.append(stmt[t:t+1])
                        t+=1
                    types.append(tl)
                    # types.append(stmt[lastpos:index])
                    lastpos=index+2
                pass
            index+=1
        # it('done. ')
        # it('basetypename', baseTypeName)
        # it('basetype', baseType)
        # it('names ', names)
        # it('types ', types)

        return [baseTypeName, baseType, names, types]

    stmt = input().strip('\n')
    parsed=parse(stmt)
    printStmt(parsed)
    # for item in ans:
    #     print(*item)
    
    pass

solve()