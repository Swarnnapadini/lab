l=[]
count=0
n=int(input("Enter the no: of items in the list:"))
print("Enter the datas:")
for i in range(0,n):
        data=input()
        l.append(data)
for i in l:
	for j in i:
		if j=='a'or j=='A':
			count+=1
print("Total count=",count)
