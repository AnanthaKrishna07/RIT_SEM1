f=open("1.txt",mode='r') 
l=f.readlines() 
f.close() 
l2=[] 
for wd in l: 
        l2.append(wd.strip()) 
 
f2=open("2.txt",mode='w') 
l3=[] 
for i in range(0,len(l2),2): 
        l3.append(l2[i]) 
for wd in l3: 
        f2.write(wd+"\n") 
f2.close() 
 
f2=open("2.txt",mode='r') 
l4=f2.readlines() 
f2.close() 
print(l4) 
