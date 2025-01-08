str=input("Enter a string\n").lower()
d="$"
newstring=str[0]+str[1:].replace(str[0],d)
print("newstring:",newstring)
