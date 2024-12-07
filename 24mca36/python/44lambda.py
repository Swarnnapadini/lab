area_square=lambda S_side:S_side **2
area_rectangle=lambda rect_length,rect_width:rect_length * rect_width
area_triangle=lambda t_base,t_height:0.5 * t_base * t_height
S_side=int(input("Enter Square side: "))
print("Area of Square: ",area_square(S_side))
rect_length=int(input("Enter Rectangle length: "))
rect_width=int(input("Enter Rectangle width: "))
print("Area of Rectangle: ",area_rectangle(rect_length,rect_width))
t_base=int(input("Enter Triangle base: "))
t_height=int(input("Enter Triangle height: "))
print("Area of Triangle: ",area_triangle(t_base,t_height))
