'''Create a Rectangle class with attributes length and breadth and methods to find area and
perimeter. Compare two Rectangle objects by their area'''

class Rectangle:
    def __init__(self, length, breadth):
        self.length = length
        self.breadth = breadth

    def calculate_area(self):
        return self.length * self.breadth

    def calculate_perimeter(self):
        return 2 * (self.length + self.breadth)

    def compare_area(self, other):
        if not isinstance(other, Rectangle):
            raise TypeError("Can only compare with another Rectangle object")

        current_area = self.calculate_area()
        other_area = other.calculate_area()

        if current_area > other_area:
            return f"This 1st rectangle (Area: {current_area}) is larger than the  2nd rectangle (Area: {other_area})"
        elif current_area < other_area:
            return f"This 1st rectangle (Area: {current_area}) is smaller than the 2nd rectangle (Area: {other_area})"
        else:
            return f"Both rectangles have equal area: {current_area}"

print("Enter details for 1st rectangle:")
length1 = float(input("Enter length: "))
breadth1 = float(input("Enter breadth: "))
rect1 = Rectangle(length1, breadth1)

print("\nEnter details for 2nd rectangle:")
length2 = float(input("Enter length: "))
breadth2 = float(input("Enter breadth: "))
rect2 = Rectangle(length2, breadth2)

print("\1st Rectangle:")
print(f"Area: {rect1.calculate_area()}")
print(f"Perimeter: {rect1.calculate_perimeter()}")

print("\n2nd Rectangle:")
print(f"Area: {rect2.calculate_area()}")
print(f"Perimeter: {rect2.calculate_perimeter()}")

print("\nComparison:")
print(rect1.compare_area(rect2))
