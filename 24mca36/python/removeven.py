l=[]
n=int(input("Enter the no: of integers:"))
print("Enter the integers:")
for i in range(n):
	intt=int(input())
	l.append(intt)
newl=[]
for num in l:
	if num%2!=0:
		newl.append(num)
print("Result=",newl)
