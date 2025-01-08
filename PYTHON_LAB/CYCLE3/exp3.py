size=int(input("Enter the size of list:")) 
list=[] 
sum=0 
for i in range(size): 
        val=int(input("Enter a value: ")) 
        list.append(val) 
        sum=sum+val 
        print("Sum: ",sum)
