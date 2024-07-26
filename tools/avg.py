import math

nums = input("Values To Average: ")
numList = nums.split(',')

j = 0
while j < len(numList):
    numList[j] = float(numList[j])
    j += 1
i = 0
total = 0

for number in numList:
    total += number
    i += 1

print("Average= ", total/i)