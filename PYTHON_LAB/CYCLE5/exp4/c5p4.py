from palindrome import ispal
def longpal(s):
        longest = ""
        for i in range(len(s)):
                for j in range(i+1, len(s) + 1):
                        if ispal(s[i:j]) and len(s[i:j]) > len(longest):
                                longest= s[i:j]
        return  longest
s=input("Enter a string:")
print("The longest palindrome substring:",longpal(s))
