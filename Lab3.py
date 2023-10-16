import sys #used to allow KeyboardInterrupt exit from While - Try/Except loop because Ctrl+C was not working in the program loop

#This is a list of valid inputs for calcType (Type of calculation) to check against input
validCalc = "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE", "A", "S", "M", "D"

#Get two numbers from user
def Get2Numbers():
    numbers = input("Please enter two numbers: ")
    firstNum, secondNum = [float(x) for x in numbers.split()]
    return firstNum, secondNum

#Get calculation type from user
#NOTE: Used While loop here because:
## 1) I didn't want the user to have re-input numbers if an input mistake was made
## 2) Because it's always a string input from console, I don't have to worry about type errors when checking it against my valid inputs list
def GetCalcType():
    while True:
        calcType = input("Calculation Type? (Add (a), Subtract (s), Multiply (m), or Divide (d)): ").upper()
        if calcType in validCalc:
            break
        else:
            print("Please enter a valid calculation type.")
            continue
    return calcType

#Perform calculation and print result
def DoCalc(firstNum, secondNum, calculation):
    
    if calculation == "ADD" or calculation == "A":
        print(str(firstNum) + " + " + str(secondNum) + " = " + str(firstNum + secondNum))
    elif calculation == "SUBTRACT" or calculation == "S":
        print(str(firstNum) + " - " + str(secondNum) + " = " + str(firstNum - secondNum))
    elif calculation == "MULTIPLY" or calculation == "M":
        print(str(firstNum) + " x " + str(secondNum) + " = " + str(firstNum * secondNum))
    elif calculation == "DIVIDE" or calculation == "D":
        print(str(firstNum) + " / " + str(secondNum) + " = " + str(firstNum / secondNum))
    else:
        print("Calculation error, please try again." + calculation)

#Start program and loop until correct inputs are given or KeyboardInterrupt
while True:
    try:
        firstNum, secondNum = Get2Numbers()
        calcType = GetCalcType()
        DoCalc(firstNum, secondNum, calcType)
        break
    except KeyboardInterrupt:
        sys.exit(0)
    except:
        print("I'm sorry, that's an invalid input.")