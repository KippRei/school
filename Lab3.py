def Get2Numbers():
    numbers = input("Please enter two numbers: ")
    firstNum, secondNum = [float(x) for x in numbers.split()]
    return firstNum, secondNum

def GetCalcType():
    calcType = input("Calc Type?: ").upper()
    return calcType

def DoCalc(firstNum, secondNum, calculation):
    if calculation == "ADD":
        print(firstNum + secondNum)
    elif calculation == "SUBTRACT":
        print(firstNum - secondNum)
    elif calculation == "MULTIPLY":
        print(firstNum * secondNum)
    elif calculation == "DIVIDE":
        print(firstNum / secondNum)
    else:
        print("Cannot calculate")
while True:
    try:
        firstNum, secondNum = Get2Numbers()
        calcType = GetCalcType()
        DoCalc(firstNum, secondNum, calcType)
        break
    except:
        print("I'm sorry, that's an invalid input")