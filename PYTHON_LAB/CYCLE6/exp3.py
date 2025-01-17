'''Write a program that has an abstract class Polygon. Derive two classes Rectangle and
Triangle from Polygon and write methods to get the details of their dimensions and hence
calculate the area'''

from abc import ABC, abstractmethod

class Polygon(ABC):
    @abstractmethod
    def get_dimensions(self):
        pass

    @abstractmethod
    def calculate_area(self):
        pass

class Rectangle(Polygon):
    def get_dimensions(self):
        self.length = float(input("Enter length: "))
        self.width = float(input("Enter width: "))

    def calculate_area(self):
        return self.length * self.width

class Triangle(Polygon):
    def get_dimensions(self):
        self.base = float(input("Enter base: "))
        self.height = float(input("Enter height: "))

    def calculate_area(self):
        return 0.5 * self.base * self.height

while True:
    print("\n**** Polygon Area's****")
    print("1. Rectangle")
    print("2. Triangle")
    print("3. Exit")

    choice = input("Enter your choice: ")

    if choice == '1':
        rect = Rectangle()
        rect.get_dimensions()
        print(f"Rectangle Area: {rect.calculate_area()}")

    elif choice == '2':
        tri = Triangle()
        tri.get_dimensions()
        print(f"Triangle Area: {tri.calculate_area()}")

    elif choice == '3':
        print("Thank you !")
        break

    else:
            print("Invalid choice....")
