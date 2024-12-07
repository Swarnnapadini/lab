import math
n=int(input("Enter the number:"))
if n<0:
	print("No factorial for negative numbers")
else:
	f=math.factorial(n)
	print("Factorial=",f)
