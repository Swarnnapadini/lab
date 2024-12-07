def is_prime(num):
	if num<1:
		return False
	for i in range(2,int(num**0.5)+1):
		if num%i==0:
			return False
	return True
def nth_prime(n):
	count=0
	number=2
	while True:
		if is_prime(number):
			count+=1
			if count==n:
				return number
		number+=1
n=int(input("Enter the position of prime number:"))
if n<0:
	print("Invalid input")
else:
	print(f"{n} th prime number is {nth_prime(n)}")
