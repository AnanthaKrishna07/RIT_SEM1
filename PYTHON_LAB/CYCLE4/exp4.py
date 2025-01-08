square=lambda side:side*side 
rectangle=lambda l,b:l*b 
triangle=lambda base,height:0.5*base*height 
print("\n*****AREA OF SQUARE*****") 
side=float(input("Enter the side of the Square: ")) 
print(f"Area is {square(side)}") 
print("\n*****AREA OF RECTANGLE*****") 
l=float(input("Enter the Length: ")) 
b=float(input("Enter the Breadth: ")) 
print(f"Area is {rectangle(l,b)}")
print("\n*****AREA OF TRIANGLE*****") 
base=float(input("Enter the base of the triangle: ")) 
height=float(input("Enter the height of th triangle: ")) 
print(f"Area is {triangle(base,height)}") 
