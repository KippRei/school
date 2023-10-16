#TODO: make switch function

#TODO: for testing
calcType = "add"

def Get2Numbers():
    numbers = input("Please enter two numbers: ")
    firstNum, secondNum = [float(x) for x in numbers.split()]
    calcType = input("Calc Type?: ").upper()
    return firstNum, secondNum

def DoCalc(firstNum, secondNum, calculation):
    match calculation:
        case "ADD":
            print(firstNum + secondNum)
        case "SUBTRACT":
            print(firstNum - secondNum)
        case _:
            print("Could not calculate")

try:
    firstNum, secondNum = Get2Numbers()
    DoCalc(firstNum, secondNum, calcType)
except:
    print("I'm sorry, that's an invalid input")
    Get2Numbers()