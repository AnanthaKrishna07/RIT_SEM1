import cmath
import math
a=float(input("Enter the coefficient of a: "))
b=float(input("Enter the coefficient of b: "))
c=float(input("Enter the coefficient of c: "))
d=(b**2) - (4*a*c)
if d>0:
        ans1=(-b-math.sqrt(d))/(2*a)
        ans2=(-b+math.sqrt(d))/(2*a)
        print(f"The roots are real:  {ans1} and {ans2}")
elif d<0:
        ans1=(-b-cmath.sqrt(d))/(2*a)
        ans2=(-b+cmath.sqrt(d))/(2*a)
        print(f"Roots are complex: {ans1} and {ans2}")
else:
        ans1=-b/(2*a)
        print(f"Roots are equal: {ans1}")
