import math
print("Quadratic equation ax^2 +bx +c")
a=float(input("Enter a value for a:"))
b=float(input("Enter a value for b:"))
c=float(input("Enter a value for c:"))
nume=(b*b)-(4*a*c)
if nume==0:
	print("Only one root is possible")
	ans=(-b)/(2*a)
	print(f"x1={ans}")
elif nume>0:
	sqrtvalue=math.sqrt(nume)
	ans1=(-b + sqrtvalue)/(2*a)
	ans2=(-b - sqrtvalue)/(2*a)
	print(f"x1={ans1}")
	print(f"x2={ans2}")

else:
	print("Complex number")
	sqrtvalue=math.sqrt(abs(nume)/(2*a))
	real_part=-b/(2*a)
	print(f"{real_part} + i{sqrtvalue}")
	print(f"{real_part} - i{sqrtvalue}")

