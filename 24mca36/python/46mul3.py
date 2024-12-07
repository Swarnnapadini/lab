r=int(input("Enter the range:"))
numbers=range(1,r)
mul=list(filter(lambda x:x%3==0,numbers))
print("Multiples of 3 are:",mul)
