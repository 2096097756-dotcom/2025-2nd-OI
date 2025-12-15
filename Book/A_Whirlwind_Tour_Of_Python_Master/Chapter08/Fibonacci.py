a,b=0,1
amax=100
L=[]

while True:
    (a,b)=(b,a+b)
    if a>amax:
        break
    L.append(a)
    
print(L)