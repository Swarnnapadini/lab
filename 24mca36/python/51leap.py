import calendar
yr=int(input("Enter the year:"))
if calendar.isleap(yr):
	print("Year ",yr,"is a leap year")
else:
	print("Year ",yr,"is not a leap year")

