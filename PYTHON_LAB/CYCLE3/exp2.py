a,b =0,1 
num = int(input("Enter the limit: ")) 
if num>0: 
    print("Fibonacci series:") 
    if num >= 1: 
        print(a) 
    if num >= 2: 
        print(b) 
    for i in range(3,num+1): 
        c = a + b 
        a = b 
        b = c 
        print(c)