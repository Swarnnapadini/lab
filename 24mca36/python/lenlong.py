n=int(input("Enter the no: of words:"))
l=[]
print("Enter the words:")
for i in range(n):
	w=input()
	l.append(w)
max_len=0
for i in l:
	if len(i)>max_len:
		max_len=len(i)
		word=i
print("Longest word=",word)
print("Length of longest word=",max_len)
