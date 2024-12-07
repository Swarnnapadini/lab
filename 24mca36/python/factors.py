n=int(input("Enter the number:"))
f=1
print("Factors are:")
while f<=n:
	if n%f==0:
		print(f)
	f=f+1
