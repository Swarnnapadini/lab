l=[]
n=int(input("Enter the no: of items in the list:"))
print("Enter the colors:")
for i in range(0,n):
	data=input()
	l.append(data)
print(l)
print("First element=",l[0],"\nLast element=",l[n-1])



