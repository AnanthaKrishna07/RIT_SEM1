n=int(input("Enter the limit:")) 
sum=0 
for i in range (1,n): 
        if i%6==0 and i%4!=0: 
                sum=sum+i 
print(f"sum is: {sum}") 
