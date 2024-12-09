import graphics.rectangle as r
import graphics.circle as c
import graphics.threegraphics.cuboid as cu
import graphics.threegraphics.sphere as s

len=int(input("Enter the length of the rectangle:"))
bre=int(input("Enter the breadth of the rectangle:"))
print("Area of rectangle=",r.area(len,bre))
print("Perimeter of rectangle=",r.perimeter(len,bre))

r1=int(input("\nEnter the radius of the circle:"))
print("Area of circle=",c.area(r1))
print("Circumference of the circle=",c.circumference(r1))

len1=int(input("\nEnter the length of the cuboid:"))
bre1=int(input("Enter the breadth of the cuboid:"))
hei1=int(input("Enter the height of the cuboid:"))
print("Area of cuboid=",cu.area(len1,bre1,hei1))
print("Perimeter of cuboid=",cu.perimeter(len1,bre1,hei1))

r2=int(input("\nEnter the radius of the sphere:"))
print("Area of sphere=",s.area(r2))
print("Volume of sphere=",s.volume(r2))
