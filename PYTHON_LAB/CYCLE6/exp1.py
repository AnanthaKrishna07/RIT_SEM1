'''Define a class to represent a bank account. Include the following details like name of the
depositor, account number, type of account, balance amount in the account. Write methods to
assign initial values, to deposit an amount, withdraw an amount after checking the balance, to
display details such as name, account number, account type and balance.'''

class BankAccount:
    def __init__(self, name, account_number, balance=0):
        self.name = name
        self.account_number = account_number
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Deposited Amount:${amount}")
        else:
            print("Invalid deposit amount")

    def withdraw(self, amount):
        if amount > 0 and amount <= self.balance:
            self.balance -= amount
            print(f"Withdraw Amount:${amount}")
        else:
            print("Invalid withdrawal amount")

    def display_details(self):
        print(f"\nAccount Holder Name: {self.name}")
        print(f"Account Number: {self.account_number}")
        print(f"Bank Balance: ${self.balance}")

def get_valid_float(prompt):
    while True:
        value = input(prompt)
        if value.replace('.', '', 1).isdigit():
            return float(value)
        print("Please enter a valid number.")

name = input("Enter your name: ")
account_number = input("Enter account number: ")

while True:
    initial_balance = get_valid_float("Enter initial Account balance: $")
    if initial_balance >= 0:
        break
    print("Balance cannot be negative. Try again.")

account = BankAccount(name, account_number, initial_balance)

while True:
    
    print("\n****Bank Account ****")
    print("1. Deposit")
    print("2. Withdraw")
    print("3. Check Balance")
    print("4. Exit")
    choice = input("Enter your choice: ")
    if choice == '1':
        amount = get_valid_float("Enter deposit amount: $")
        account.deposit(amount)

    elif choice == '2':
        amount = get_valid_float("Enter withdrawal amount: $")
        account.withdraw(amount)

    elif choice == '3':
        account.display_details()

    elif choice == '4':
        print("Thank you !")
        break

    else:
        print("Invalid choice. Please try again.")

