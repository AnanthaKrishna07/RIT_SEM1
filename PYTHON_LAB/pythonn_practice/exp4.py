#From a list of integers, create a list after removing even numbers

numbers=[1,2,3,4,5,6,7,8,9]

def removenumbers():
    return[r_numbers for r_numbers in numbers if r_numbers % 2!=0]


r_numbers=removenumbers()

print("After removing even numbers:",r_numbers)
