import math 
def sum_of_digits(n): 
    return sum(int(digit) for digit in str(n)) 
def is_prime(n): 
    if n <= 1: 
        return False
    if n == 2:   
        return True 
    if n % 2 == 0:   
        return False 
    for i in range(3, int(math.sqrt(n)) + 1, 2): 
        if n % i == 0: 
            return False 
    return True 
def sum_digits_in_range(upper_limit): 
    for num in range(1, upper_limit + 1): 
        digit_sum = sum_of_digits(num) 
        if is_prime(digit_sum): 
            print(f"Sum of digits of {num} is {digit_sum}, which is prime.") 
limit = int(input("Enter an upper limit: ")) 
sum_digits_in_range(limit) 
