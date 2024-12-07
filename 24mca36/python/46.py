r=int(input("Enter range:"))
lt=[]
for i in range(r):
        n=int(input("Enter numbers:"))
        lt.append(n)
numbers=lt
multiples_of_3=list(filter(lambda x:x%3==0,numbers))
print("Multiples of 3:",multiples_of_3)


