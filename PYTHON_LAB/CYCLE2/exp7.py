list1=input("Enter the color of list1").split(",")
list2=input("Enter the color of list2").split(",")
result=[]
for char in list1:
    if char not in list2:
        result.append(char)
print(f"color in list1 but not in list2 are: {result}")
