import json

def addExpense(expenses, desc, amt):
    expenses.append({"desc": desc, "amt": amt})
    print(f"Added expense: {desc}\nAmount: {amt}")

def addIncome(incomes, desc, amt):
    incomes.append({"desc": desc, "amt": amt})
    print(f"Added income: {desc}\nAmount: {amt}")

def getTotalExpenses(expenses):
    total = 0.0
    for expense in expenses:
        total += expense["amt"]

    return total

def getTotalIncome(incomes):
    total = 0.0
    for income in incomes:
        total += income["amt"]

    return total

def getBalance(budget, expenses, incomes):
    return budget - getTotalExpenses(expenses) + getTotalIncome(incomes)

def showBudget(budget, expenses, incomes):
    print(f"Total budget: {budget}")

    print("Expenses:")
    for expense in expenses:
        print(f"- {expense["desc"]}: {expense["amt"]}")

    print("Income:")
    for income in incomes:
        print(f"+ {income["desc"]}: {income["amt"]}")

    print(f"Total spent: {getTotalExpenses(expenses)}")
    print(f"Total income: {getTotalIncome(incomes)}")
    print(f"Remaining budget: {getBalance(budget, expenses, incomes)}")

def loadBudgetData(filepath):
    try:
        with open(filepath, 'r') as file:
            data = json.load(file)
            return data["initBudget"], data["expenses"], data["incomes"]
    except (FileNotFoundError, json.JSONDecodeError):
        return 0, [], [] # default values if file doesn't exist or is empty/corrupted

def saveBudgetData(filepath, initBudget, expenses, incomes):
    data = {
        "initBudget": initBudget,
        "expenses": expenses,
        "incomes": incomes
    }
    
    with open(filepath, 'w') as file:
        json.dump(data, file, indent=4)

def main():
    print("Budget Tracker: Stop Wasting Money!")

    filepath = "budgetData.json"
    initBudget, expenses, incomes = loadBudgetData(filepath)

    if initBudget == 0:
        initBudget = float(input("Please enter your initial budget: "))

    budget = initBudget

    while True:
        print("\nWhat would you like to do?")
        print("1. Add expense")
        print("2. Add income")
        print("3. Show budget details")
        print("Q. Quit")

        choice = input("Enter your choice (1/2/3/q): ")

        ## EXPENSE ##
        if choice == "1":
            desc = input("Enter expense description: ")
            amt = float(input("Enter expense amount: "))
            addExpense(expenses, desc, amt)
            
        ## INCOME ##
        elif choice == "2":
            desc = input("Enter income description: ")
            amt = float(input("Enter income amount: "))
            addIncome(incomes, desc, amt)

        ## SHOW BUDGET DETAILS ##
        elif choice == "3":
            showBudget(budget, expenses, incomes)

        ## SAVE AND EXIT ##
        elif choice == "q" or choice == "Q":
            saveBudgetData(filepath, initBudget, expenses, incomes)
            print("Exiting budget tracker.")
            break

        ## INVALID INPUT ##
        else:
            print("Invalid input. Please try again.")

if __name__ == "__main__":
    main()

