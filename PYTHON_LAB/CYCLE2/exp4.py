str=input("Enter the string: ")
char_count={}
for char in str:
        if char in char_count:
                char_count[char]+=1
        else:
                char_count[char]=1
print("Character frequency: ")
print(char_count)
