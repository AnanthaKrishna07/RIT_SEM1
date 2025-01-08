from graphics.rectangle import rarea as rect_area,rperimeter as rect_perimeter
from graphics.circle import carea as circ_area,cperimeter as circ_perimeter

from graphics.graph3d.cuboid import *
from graphics.graph3d.sphere import *

rlength=float(input("Enter the length of rectangle:"))
rwidth=float(input("Enter the width of rectangle:"))
print(f"Rectangle Area:{rect_area(rlength,rwidth)}")
print(f"Rectangle Perimeter:{rect_perimeter(rlength,rwidth)}")

cradius=float(input("Enter the radius of circle:"))
print(f"Circle Area:{circ_area(cradius)}")
print(f"Circle Perimeter:{circ_perimeter(cradius)}")

length=float(input("Enter the length of cuboid:"))
width=float(input("Enter the width of cuboid:"))
height=float(input("Enter the height of cuboid:"))
print(f"Cuboid Area:{cuarea(length,width,height)}")
print(f"Cuboid Volume:{cuvolume(length,width,height)}")

radius=float(input("Enter the radius of sphere:"))
print(f"Sphere Area:{sparea(radius)}")
print(f"Sphere Volume:{spvolume(radius)}")
