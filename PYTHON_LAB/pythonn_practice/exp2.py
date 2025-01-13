''' List comprehensions: 
(a) Generate positive list of numbers from a given list of integers 
(b) Square of N numbers 
(c) Form a list of vowels selected from a given word 
(d) Form a list ordinal value of each element of a word (Hint: use ord() to get ordinal values) 
Ordinal Value - Displaying ASCII code of each character''' 


nums = [-10,15,-20,25,30]
positive_nums = [n for n in nums if n>0]
print("Positive numbers",positive_nums)

N=5
squares=[i**2 for i in range(1,N+1)]
print("Squares: ",squares)

word = "comprehension"
vowels = [ch for ch in word if ch in 'aeiou']
print("vowels: ",vowels)


ordinals = [ord(ch) for ch in word]
print("Ordinal values: ",ordinals)
