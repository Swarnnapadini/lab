numbers=[-70,15,8,3,4,-9,0,-2]
p=[num for num in numbers if num>0]
print("Positive numbers:",p)
n=5
squares=[num**2 for num in range(1,n+1)]
print("Squares of N numbers:",squares)
word="hello world"
vowels=[char for char in word if char in'aeiou']
print("Vowels are:",vowels)
w="hello"
ordinal=[ord(char) for char in w]
print("Ordinal values of each characters:",ordinal)
