#Quadratic Formula
import math

val = str

def qe(a,b,c):
    x1 = -b + math.sqrt((b**2 - 4*(a*c)))
    x1 = x1 / (2*a)
    x2 = -b - math.sqrt((b**2 - 4*(a*c)))
    x2 = x2 / (2*a)
    print("= ", x1, " and ", x2)

def GetInput():
    val = input("Enter values: ")
    val = val.split(",")
        
    try:
        a = float(val[0])
        b = float(val[1])
        c = float(val[2])
        qe(a,b,c)
    except:
        print("Invalid Input Please Try Again")
        GetInput()

GetInput()