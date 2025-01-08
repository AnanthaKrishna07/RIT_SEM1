def fact(x): 
    f=1 
    for i in range(1,x+1): 
        f=f*i 
    return f 
n=int(input("Enter the number of terms: ")) 
terms=list(map(lambda x:(x**x)/fact(x),range(1,n+1))) 
sum=0 
for s in terms: 
    sum+=s 
print(f"sum of terms = {sum}")
