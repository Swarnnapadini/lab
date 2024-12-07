str=input("Enter a line of text:")
words=str.split()
count={}
for word in words:
	word.lower()
	if word in count:
		count[word]+=1
	else:
		count[word]=1
print("Word occuurances:",count)
