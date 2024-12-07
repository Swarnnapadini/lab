def factorial(num):
        if num==1 or num==0:
                return 1
        else:
                fact=1
                for i in range(2,num+1):
                        fact=fact*i
                return fact
def Permutation(n,r):
        return factorial(n) // factorial(n-r)

def Combination(n,r):
        return factorial(n) // (factorial(r) * factorial(n-r))

n=int(input("Enter the n value: "))
r=int(input("Enter the r value: "))
print(f"Permutations({n},{r}):{Permutation(n,r)}")
print(f"Combinations({n},{r}):{Combination(n,r)}")
