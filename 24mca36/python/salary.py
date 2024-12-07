basic_pay=float(input("Enter the basic pay:"))
hra=0.10*basic_pay
ta=0.05*basic_pay
total=basic_pay+hra+ta
print(f"Basic Pay:{basic_pay}\nHRA:{hra}\nTA:{ta}\nTotal Salary:{total}")
