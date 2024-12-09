from fpalindrome import palindrome
def long_palindrome(s):
	longest=""
	for i in range(len(s)):
		for j in range(i+1,len(s)+1):
			substring=s[i:j]
			if palindrome(substring) and len(substring)>len(longest):
				longest=substring
	return longest
str1=input("Enter string:")
result=long_palindrome(str1)
print("Longest palindrome substring:",result)
