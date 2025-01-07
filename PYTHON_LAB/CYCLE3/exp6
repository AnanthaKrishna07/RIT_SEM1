 def pr(n): 
        count=0 
        for i in range (1,n+1): 
                if n%i==0: 
                        count=count+1 
        if count>2: 
                return 0 
        else: 
                return 1
n=int(input("Enter the limit:")) 
ls=[] 
pls=[] 
for lim in range(2,n+1): 
        ls.append(lim) 
for lim in ls: 
        if pr(lim)==1: 
                pls.append(lim) 
print(pls[::2])
