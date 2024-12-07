str1=input("Enter first string:")
str2=input("Enter second string:")
n1=len(str1)
n2=len(str2)
str1a=str1[1]
str2a=str2[1]
print(str1[0]+str2a+str1[2:n1+1]," ",str2[0]+str1a+str2[2:])
