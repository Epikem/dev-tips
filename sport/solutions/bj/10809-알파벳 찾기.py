ri = input()
# arr = list(map(int, input().split(" ")))

TEST = False
try:
  import sys
  for arg in sys.argv:
    if(arg == 'test'):
      TEST = True
  pass
except:
  pass

def it(arg):
  if(TEST):
    print(arg)

def ArrayJoin(array, separator):
  return separator.join(array)

ins = str(ri)
alphabetRange = range(ord('a'), ord('z')+1)
ans = []
for a in alphabetRange:
  ans.append(str(ins.find(chr(a))))
  it(chr(a))
print(ArrayJoin(ans, ' '))