class Bankaccount:
	def __init__(self,name,account_number,account_type,balance=0):
		self.name=name
		self.account_number=account_number
		self.account_type=account_type
		self.balance=balance
	def withdraw(self,account):
		if amount>0:
			if amount<=self.balance:
				self.balance-=amount
				print(f"{amount} withdraw successfully. new balance:{self.balance}")
			else:
				print("insufficient balance")
		else:
			print("withdraw amount musy be positive")

	def deposit(self,account):
		if amount>0:
			self.balance+=amount
			print(f"{amount} deposited succesfully. new balance:{self.balance}")
		else:
			print("deposited amount must be positive")
	def display(self):
		print("Account details..")
		print(f"name:{self.name}")
		print(f"account_number:{self.account_number}")
		print(f"account_type:{self.account_type}")
		print(f"balance:{self.balance}")


account=None
while True:
		
	print("1.create a new account")
	print("2.deposit money")
	print("3.withdraw money")
	print("4.display")
	print("5.exit")
	choice=int(input("enter your choice:"))
	if choice==1:
		name=input("enter the account holder:")
		account_number=int(input("enter the account number:"))
		account_type=input("enter the account type(savings/current):")
		initial_balance=float(input("enter the initial balance:"))
		account=Bankaccount(name,account_number,account_type,initial_balance)
		print("account created successfully")
	elif choice==2:
		if account:
			amount=float(input("enter the amount to depoist:"))
			account.deposit(amount)
		else:
			print("create an account first")
	elif choice==3:
		if account:
			amount=float(input("enter the amount to withdraw:"))
			account.withdraw(amount)
		else:
			print("create an account first")
	elif choice==4:
		if account:
			account.display()
		else:
			print("please create a account")
	elif choice==5:
		print("exiting")
		break
	else:
		print("invalid choice")
