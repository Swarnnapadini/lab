cl1=[]
cl2=[]
n1=int(input("Enter the no: of colors in first lisr:"))
print("List 1")
print("Enter colors for list 1:")
for i in range(n1):
	color=input()
	cl1.append(color)
n2=int(input("Enter the no: of colors in second list:"))
print("List 2")
print("Enter colors for list 2:")
for i in range(n2):
        color=input()
        cl2.append(color)
result=[]
for color in cl1:
	if color not in cl2:
		result.append(color)
print("Color from list 1 not in list 2:",result)
