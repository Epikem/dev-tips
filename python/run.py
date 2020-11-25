# -*- coding:utf-8 -*-
# #NYAN NYAN
#░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
#░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
#░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
#░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
#░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
#░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
#░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
#░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
#░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
#░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
#░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
#░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
#░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
from __future__ import print_function
import os
import sys
Debug = False
Conda = False
UseFileIO = True
UseLibrary = False
Archive = False
EdX = False
BOJ = False
ReadTarget = None
WriteTarget = None

try:
    import sys
    for arg in sys.argv:
        if(arg == 'test' or arg == 'debug'):
            Debug = True
            ReadTarget = 'input.txt'
            WriteTarget = None
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
libnames = ['fileinput', 'codecs', 'operator', 'functools', 'math', 'io', 'platform', 'collections', 'mmap', 'logging', 'logging.handlers']
AddImports(libnames)
IntellisenseHint = False
if IntellisenseHint:
    import fileinput
    import codecs
    import operator
    import functools
    import math
    import io
    import platform
    import collections
    import mmap
    import logging
    import logging.handlers
    # import defs

class memoized(object, ):
    "Decorator. Caches a function's return value each time it is called.\n\tIf called later with the same arguments, the cached value is returned\n\t(not reevaluated).\n\t"

    def __init__(self, func):
        self.func = func
        self.cache = {}

    def __call__(self, *args):
        if (not isinstance(args, collections.Hashable)):
            return self.func(*args)
        if (args in self.cache):
            return self.cache[args]
        else:
            value = self.func(*args)
            self.cache[args] = value
            return value

        def __repr__(self):
            "Return the function's docstring."
            return self.func.__doc__

        def __get__(self, obj, objtype):
            'Support instance methods.'
            return functools.partial(self.__call__, obj)

def readSequence(elementType=None, inputLine=None, seperator=None, strip=True):
    global readTarget
    if (inputLine == None):
        inputLine = readTarget.readline()
    if strip:
        inputLine = inputLine.strip()
    if isinstance(inputLine, bytes):
        inputLine = inputLine.decode('utf-8')
    if (elementType == None):
        return [x for x in inputLine.split(seperator)]
    return [elementType(x) for x in inputLine.split(seperator)]
rl = RobertsSpaceIndustries = readSequence

def ToSpaceSeperatedString(targetList):
    return ' '.join(map(str, targetList))

def convert_to_bytes(arg):
    if isinstance(arg, bytes):
        return arg
    elif isinstance(arg, str):
        return arg.encode('utf-8')
    elif hasattr(arg, '__iter__'):
        return ' '.join(map(convert_to_bytes, arg))
    else:
        return str(arg).encode('utf-8')

class edx_in:

    def __init__(self, target=None):
        self.target = target

    def create_lineTokenizer(self):
        if self.mm:
            for line in iter(self.mm.readline, ''):
                (yield line)
        else:
            for line in iter(self.stream.readline, ''):
                (yield line)

    def __enter__(self):
        if (self.target and UseFileIO):
            self.isFileEmpty = (os.stat(self.target).st_size == 0)
            if self.isFileEmpty:
                return self
            self.stream = open(self.target, 'rb', 1)
            self.mm = mmap.mmap(self.stream.fileno(), 0, access=mmap.ACCESS_READ)
        else:
            self.mm = None
            self.isFileEmpty = True
            self.stream = sys.stdin
        self.lines = self.create_lineTokenizer()
        self.lineTokens = None
        return self

    def __exit__(self, type, value, traceback):
        if (not self.isFileEmpty):
            if self.mm:
                self.mm.close()
            self.stream.close()

    def next_line(self):
        ret = None
        try:
            ret = ' '.join(self.lineTokens)
            self.lineTokens.close()
            if (ret == ''):
                raise ValueError()
            return ret
        except:
            pass
        if hasattr(self.lines, 'next'):
            ret = self.lines.next()
        if hasattr(self.lines, '__next__'):
            ret = self.lines.__next__()
        return ret

    def next_int(self):
        return int(self.next_token())

    def next_float(self):
        return float(self.next_token())

    def next_str(self, encoding=None):
        if encoding:
            return self.next_token().decode(encoding)
        else:
            return self.next_token()

    def getLineTokens(self, line):
        for token in iter(line.split()):
            (yield token)

    def nextNToken(self, rep=0):
        ans = []
        while (rep > 0):
            ans.append(self.next_token())
            rep -= 1
        return ans

    def next_token(self):
        try:
            if hasattr(self.lineTokens, 'next'):
                ret = self.lineTokens.next()
            if hasattr(self.lineTokens, '__next__'):
                ret = self.lineTokens.__next__()
            return ret
        except:
            self.lineTokens = self.getLineTokens(self.next_line())
            return self.next_token()

class edx_out:

    def __init__(self, target=None):
        self.target = target

    def __enter__(self):
        self.is_cpython = (platform.python_implementation() == 'CPython')
        if (self.target and UseFileIO):
            if self.is_cpython:
                self.stream = open(self.target, 'wb', 1)
            else:
                self.stream = io.BytesIO()
        else:
            self.stream = sys.stdout
        return self

    def __exit__(self, type, value, traceback):
        if (self.target and UseFileIO):
            if self.is_cpython:
                self.stream.close()
            else:
                outf = open(self.target, 'wb', 1)
                outf.write(self.stream.getvalue())
                outf.close()
                self.stream.close()
        else:
            pass

    def write(self, arg):
        self.stream.write(convert_to_bytes(arg))

    def writeln(self, arg):
        self.write(arg)
        self.write('\n')

    def test(self, expression):
        frame = sys._getframe(1)
        exp = expression
        ans = repr(eval(exp, frame.f_globals, frame.f_locals))
        self.debug(((('test : ' + exp) + ' = ') + ans))
        pass
sys.setrecursionlimit(2000)

class UseFunctions:
    it = True
    useless = True
    DisplayMembersPage = False
    '\n\tThis class checks whether a user\n\thas logged in properly via\n\tthe global "check_function". If so,\n\tthe requested routine is called.\n\tOtherwise, an alternative page is\n\tdisplayed via the global "alt_function"\n\t'

    def __init__(self, f):
        self._f = f

    def __call__(self, *args):
        Status = (1 if (getattr(UseFunctions, self._f.__name__) == True) else 0)
        if (Status is 1):
            return self._f(*args)
        else:
            return

def check_function():
    return test

def solve():

    def solve1890():
        n = ri()
        m = {}
        c = {}
        c[(0,0)] = 1
        # it(c)
        # c[(1,0)] = c[(1,0)] + 1 if ((1,0) in c) else 1
        
        for y in range(n):
            for x in range(n):
                v = ri()
                # it((x,y,v))

    #   cache.setPosition(x,y+data, (cache.getPosition(x,y+data) || 0) + (cache.getPosition(x,y) || 0));
    #   cache.setPosition(x+data,y, (cache.getPosition(x+data,y) || 0) + (cache.getPosition(x,y) || 0));
                l = (x+v,y)
                r = (x,y+v)
                a = c[(x,y)] if (x,y) in c else 0
                rr = c[r] if r in c else 0
                ll = c[l] if l in c else 0
                # c[(x+v,y)] = c[(x+v,y)] + 1 if ((x+v,y) in c) else 1
                # c[(x,y+v)] = c[(x,y+v)] + 1 if ((x,y+v) in c) else 1
                c[r] = rr + a
                c[l] = ll + a
                pass
            pass

        # it(c)

        # for y in range(n):
        #     tt = []
        #     for x in range(n):
        #         tt.append(c[(x,y)] if ((x,y) in c) else 0)
        #         pass
        #     it(tt)
        #     pass

        print(c[(n-1,n-1)] // 2)
        pass

    @UseFunctions
    def it(n):
        # return range(n)
        if(Debug):
            print(n)

    @UseFunctions
    def useless(n):
        debug(n)
        pass
    solve1890()
    pass
reader = None
writer = None
try:
    logger1 = logging.getLogger('log1')
    debug = (lambda *x: logger1.log(logging.DEBUG, convert_to_bytes(x)))
    PutLevel = 100
    logging.PUT = PutLevel
    logging.addLevelName(PutLevel, 'PUT')
    logger1.setLevel(logging.PUT)
    formatter = logging.Formatter()
except:
    pass
with edx_in(ReadTarget) as Reader:
    with edx_out(WriteTarget) as Writer:
        try:
            outHandler = logging.StreamHandler(Writer.stream)
            outHandler.setFormatter(formatter)
            logger1.addHandler(outHandler)
            put = (lambda *args: logger1.log(logging.PUT, convert_to_bytes(args)))
            info = (lambda *args: logger1.log(logging.INFO, convert_to_bytes(args)))
            critical = (lambda *args: logger1.log(logging.CRITICAL, convert_to_bytes(args)))
        except:
            debug = Writer.writeln
            put = Writer.writeln
            info = Writer.writeln
            critical = Writer.writeln

        def nop(*arg):
            pass
        debug = nop
        test = nop
        info = nop
        reader = Reader
        writer = Writer
        ri = reader.next_int
        rs = reader.next_str
        rt = reader.next_token
        rf = reader.next_float
        rl = reader.next_line
        rnt = reader.nextNToken
        wl = writer.writeln
        solve()