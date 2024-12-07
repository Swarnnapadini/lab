l=int(input("Enter the upper limit:"))
tsum=0
for i in range(1,l):
	if i%6==0 and i%4!=0:
		tsum=tsum+i
print("Sum=",tsum)
