from sys import stdin,stdout

def solve(inp,out):
    
    #=int(input())
    n,k=map(int, inp().split())
    a=list(map(int, inp().split()))
    d=[]
    s=0
    p=0
    idx=0
    flag = False
    for i in range(n):
        if p>=k-1:
            idx=i
            flag = True
            break
        s+=a[i]
        if (s&1)==1:
            p+=1
            s=0
            d.append(i+1)
    if len(d)==k-1 and flag:
        s=0
        for i in range(idx,n):
            s+=a[i]
        if (s&1)==1:
            d.append(n)
    if len(d)==k:
        out("YES\n")
        for u in d:
            out(str(u)+" ")
        out("\n")
    else:
        out("NO\n")
def main():
    inp=stdin.readline
    out=stdout.write
    t=1
    if(t==0):
        test = 1
    else:
        test = int(inp())
    for _ in range(test):
        solve(inp,out)    
            
main()           