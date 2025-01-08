strone=input("Enter the first string\n")
strtwo=input("Enter the second string\n")
newstr1=strone[0]+strtwo[1:2]+strone[2:]
newstr2=strtwo[0]+strone[1:2]+strtwo[2:]
print(newstr1+" "+newstr2)
