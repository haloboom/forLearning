def choose(n,m):
    if m>n:
        return 0;
    elif m==0:
        return 1;
    return choose(n-1,m-1)+choose(n-1,m)
print("%d\n"%choose(5,2))
