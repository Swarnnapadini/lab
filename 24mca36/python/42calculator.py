def add(x,y):
	return x+y
def sub(x,y):
        return x-y

def mul(x,y):
        return x*y

def div(x,y):
	if y>0:
        	return x/y
	else:
		print("Not possible")
a=int(input("Enter the first number:"))
b=int(input("Enter the second number:"))
while(1):
	print("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division")
	ch=int(input("Enter your choice:"))
	if ch==1:
		print("Addition:",add(a,b))
	elif ch==2:
                print("Subtraction:",sub(a,b))
	elif ch==3:
                print("Multiplication:",mul(a,b))
	elif ch==4:
                print("Division:",div(a,b))
	else:
		print("Invalid choice")
		exit(0)


