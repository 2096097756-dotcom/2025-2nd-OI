L=[]
for i in range(2,300):
    for factor in L:
        if(i%factor==0):
            break
    else: 
        L.append(i)
print(L)
