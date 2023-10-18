def GetName():
    first, last = input("Please enter your first and last name (separated by a space): ").split()
    return last, first
try:
    first, last = GetName()
    print("Hi " + first + " " + last)
except Exception:
    print("try again")
    GetName()