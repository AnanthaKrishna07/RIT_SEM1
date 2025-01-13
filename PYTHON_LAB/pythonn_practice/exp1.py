''' Write a program to prompt the user to enter two lists of integers and check 
(a) Whether lists are of the same length. 
(b) Whether the list sums to the same value. 
(c) Whether any value occurs in both Lists '''


list1=list(map(int,input("Enter first list of integers:").split()))
list2=list(map(int,input("Enter second list of integers:").split()))

if len(list1) == len(list2):
    print("Lists are of the same length.")
else:
    print("Lists are of the different length.")

if sum(list1) == sum(list2):
    print("sum of the both are same.")
else:
    print("sum of the both are different.")

common_values = set(list1) & set(list2)
if common_values:
    print("Common values:",common_values)
else:
    print(" No Common values")
