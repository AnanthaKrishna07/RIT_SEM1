 def even_perfect_squares(start, end): 
    results = [] 
    start_root = int(start**0.5) 
    end_root = int(end**0.5)  
    for root in range(start_root, end_root + 1): 
        num = root * root 
        if 1000 <= num <= 9999 and num % 2 == 0: 
            digits = str(num) 
            if all(int(digit) % 2 == 0 for digit in digits): 
                results.append(num)   
    return results
start_range = int(input("Enter start range: ")) 
end_range = int(input("Enter end range: ")) 
result = even_perfect_squares(start_range, end_range) 
 
if result: 
    print(f"Even perfect squares: {result}") 
else: 
    print("No perfect squares found in the specified range.") 
