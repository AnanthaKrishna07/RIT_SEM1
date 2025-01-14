''' Create a string from the given string where the first and last character are exchanged. 
Eg: Python ⇒ nythoP  
Get a string from an input string where all occurrences of the first character are replaced 
with ‘$’, except the first character. [eg: onion -> oni$n] '''

def swap(swappedstr):
    if len(swappedstr)>1:
        return swappedstr[-1] + swappedstr[1:-1] + swappedstr[0]
    return swappedstr

def swapfull(fswap):
    if len(fswap)>1:
        return fswap[::-1]
    return fswap

def replacefirst(strings):
    first_r= strings[0]
    return first_r + strings[1:].replace(first_r,"$")

    

strings=input("Enter a string: ")

swappedstr=swap(strings)
fswap=swapfull(strings)
rfirst=replacefirst(strings)

print("SWapped string:",swappedstr)
print("Fully SWapped string:",fswap)
print("First element replaced:",rfirst)
