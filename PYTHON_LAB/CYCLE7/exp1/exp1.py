f=open("1.txt",mode='r') 
l=[] 
l.append(f.readline()) 
l.append(f.readline()) 
l.append(f.readline()) 
l.append(f.readline()) 
f.close() 
l2=[] 
for wd in l: 
        l2.append(wd.strip()) 
print(l2) 
