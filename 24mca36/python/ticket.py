age=int(input("Enter the age:"))
if age<10:
	print("Ticket rate for trade fair is 7")
elif 10<=age<60:
	print("Ticket rate for trade fair is 10")
elif age>=60:
	print("Ticket rate for trade fair is 5")
else:
	print("Enter proper age")
