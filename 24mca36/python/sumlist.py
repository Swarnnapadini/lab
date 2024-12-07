n=int(input("Enter the no: of terms:"))
l=[]
print("Enter the numbers:")
for i in range(n):
	num=int(input())
	l.append(num)
sum=sum(l)
print("Sum=",sum)
