color_list1=input("Enter color for list1 seperated by comma:" ).split(",")
color_list2=input("Enter color for list2 seperated by comma:" ).split(",")
color_list1=set(color_list1)
color_list2=set(color_list2)
result=color_list1-color_list2
print("colors in list1 but not in list2 are: ",result)
