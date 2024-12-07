lt=[]
n=int(input("Enter no.of terms:"))
for i in range(n):
        terms=int(input("Enter terms: "))
        lt.append(terms)
twox=lambda x:2**x
power_of_2=map(twox,lt)
print("Powers of 2:")
power_fnctn_list=list(power_of_2)
print(power_fnctn_list)
