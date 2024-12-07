l=[]
n=int(input("Enter the no: of numbers:"))
print("Enter the numbers:")
for i in range(n):
	intt=int(input())
	l.append(intt)
result=[]
for num in l:
	if num>100:
		result.append('over')
	else:
		result.append(num)
print("Result=",result)
