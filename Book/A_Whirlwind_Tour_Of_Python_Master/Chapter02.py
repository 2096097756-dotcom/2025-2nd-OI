import this # The Zen of Python, by Tim Peters
midpoint=5
lower=[];upper=[]

for i in range(10):
    if (i<midpoint):
        lower.append(i)
    else:
        upper.append(i)
print('the lower append:',lower)
print('the upper append',upper)