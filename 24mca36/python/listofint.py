l1=[]
l2=[]
n1=int(input("Enter the no: of integers in list 1:"))
print("Enter the numbers:")
for i in range(n1):
	val=int(input())
	l1.append(val)
n2=int(input("Enter the no: of integers in list 2:"))
print("Enter the numbers:")
for i in range(n2):
        val=int(input())
        l1.append(val)
if n1==n2:
	print("Two lists are of same length")
else:
	 print("Two lists are not of same length")
if sum(l1)==sum(l2):
	print("Two lists are of same sum value")
else:
	print("Two lists are not of same sum value")
com_value=any(num in l2 for num in l1)
print("Common value:",com_value)
