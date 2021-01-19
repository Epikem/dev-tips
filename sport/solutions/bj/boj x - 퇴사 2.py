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

profits = [0]*1500005
limits = {} # [[3,40], [1,70]] -> 3일 남은 일이 40포인트, 1일 남은 일이 70포인트
def solve():
    n = ria()[0]
    # def getMax(day):
    #     if(profits[day]!=0):
    #         return profits[day]

    #     maxv = 0


    #     return

    for nn in range(1, n+1, 1):
        t,p = ria()
        ## k일째까지의 최대 수익 = max(k-50~k-1 까지의 최대 수익 +p(k-50)~p(k-1))
        # n=150,0000 * 50 -> 7500 0000 너무 클거 같다.
        # 그렇다면 어떻게 해야하지?
        # 이동평균 구하듯이 해야할거 같은데
        # 그냥 1일부터 읽으면서, 이 날이 영향을 주는 모든 날들에 칸들에서 고려하게 defer 해도
        # 될거같은데. 구체적으로 어떻게?
        # 1일에 x일 걸린다고 되어있으면, 1일을 고를 경우 그후 x일은 빼야하게 된다.
        # 지금 문제가, dp로 이전 정보를 저장한다고 해도,
        # 그 다음 1일을 구하는데는 이전 최대 50일까지를 확인해 보아야 한다는 것이 문제다.
        # 그렇다면 그걸 어떻게 해결할까?
        # 한 날을 처리하는건 확실히 한 번의 연산으로 끝내야 한다.
        # 날을 읽으면서 남은 기간 카운트 리스트를 만들어서,
        # 인덱스가 증가하면서 만료했는지 확인해서 만료됬다면 해당하는 날짜에 대해서는 체크를?
        # 그렇다. 그 기준 이전 날짜들에 할 필요는 없다. 이미 그 날짜의 profit이 최대이므로.
        # 이렇게 해도 어차피 그 날짜가 이미 잘려있을 것들에 대해서 계산하는건 막을 수 있으므로
        # 문제는 이렇게 할 경우 대부분이 만약 50일이 기간이라면 소용이 없다.
        # dictionary를 써야 하나?

        # 아니다. 잘못된 가정이었다. 해당 상담이 끝나는 날짜에 해당하는 상담이 좋지 않아서
        # 끝나고 조금 나중에 해당하는 날짜를 골라야 할 때, 
        # 이전 날짜 정보를 기억하지 않으면 언제로 정해야 할 지 알 수가 없다?\

        # 예를 들어 마지막 예제에서,
        # 2 20을 상담이 끝나서 고르게 되면서, 3 30은 고르지 않게 된다.
        # 3 30을 고르려면, 2 20을 할 때 그 다음날에 대해서는 더하지 않은 정보를 넣는 식으로
        # 해도 될거 같다.

        # 의사 코드를 써보자. 먼저 현재 인덱스가 k라고 하고,
        # k번째 날에 만료되는 상담이 있는지 확인한다. 
        if(nn+t-1>n):
            # it(nn,t,n,nn+t-1,n)
            p = -999999990
        # if(nn==8):
        #     it('nnn', nn)
        #     it(limits)
        if(nn in limits.keys()):
            # 있다면, 그 키쌍의 값들을 꺼내고 키쌍은 제거한다.
            values = limits.pop(nn)
            # it('values', values, p) 
            maxp = 0
            maxd = 0
            for d in values:
                # 여기에 있는 각 날짜 d들을 순회하면서, 가장 높은 profits[d]를 찾는다.
                # 그 날짜 d를 외워둔다
                # it('d ', d, profits[d])
                if(profits[d] > maxp):
                    maxp=profits[d]
                    maxd = d
            # 오늘 날짜의 최고 값은 k_p + profits[d_max]가 된다.
            # profits[nn] = p + profits[maxd] if p + profits[maxd]>profits[nn-1]+p else profits[nn-1]+p
            it('p+profits[maxd], profits[nn-1]', nn, p+profits[maxd], profits[nn-1])
            profits[nn] = max(p+profits[maxd], profits[nn-1])
            # it('profits 1',nn, profits[nn])
            # 오늘의 상담이 끝나는 그 다음날에 오늘을 등록한다.
            if(nn+t in limits.keys()):
                limits[nn+t].append(nn)
            else:
                limits[nn+t]=[nn]
            
            # 오늘을 고르지 않는 경우에 대해서도 등록한다... 안된다.
            # 이렇게 하면 nn-1일의 일이 끝난 것처럼 되어버린다.
            if(nn+1 in limits.keys() ):
                limits[nn+1].append(nn-1)
            else:
                limits[nn+1]=[nn-1]
            # if(nn+1 in limits.keys() and profits[nn]==profits[nn-1]):
            #     limits[nn+1].append(nn-1)
            # else:
            #     limits[nn+1]=[nn-1]
            
        else:
            # 오늘 날짜의 최고 값은 k_p가 된다.
            profits[nn] = p if p>profits[nn-1] else profits[nn-1]
            # profits[nn] = profits[nn-1]+p
            it('profits 2',nn, profits[nn])
            # 오늘의 상담이 끝나는 그 다음날에 오늘을 등록한다.
            if(nn+t in limits.keys()):
                limits[nn+t].append(nn)
            else:
                limits[nn+t]=[nn]

            # 오늘을 고르지 않는 경우에 대해서도 등록한다.
            if(nn+1 in limits.keys() ):
                limits[nn+1].append(nn-1)
            else:
                limits[nn+1]=[nn-1]

            pass


    print(profits[n])

    
    pass

solve()