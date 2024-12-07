n=int(input("Enter a number:"))
sum=0
temp=n
num=len(str(n))
while n>0:
	r=n%10
	sum+=r**num
	n//=10
if temp==sum:
	print("Amstrong number")
else:
	print("Not amstrong number")
