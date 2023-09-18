## Calculate Standard Deviation of Data Set
import math

dataPoints = input("Insert Data Points Seprated By Comma: ")
dataList = dataPoints.split(',')

sumOfData = 0
n = 0

for i in dataList:
    n = n + 1
    sumOfData = float(i) + sumOfData
mean = sumOfData / n

standDevSum = 0

for i in dataList:
    standDevSum = standDevSum + (float(i) - mean) ** 2
print(standDevSum)
standDevSum = standDevSum / (n - 1)
print(standDevSum)
standDev = math.sqrt(standDevSum)

print("Standard Deviation: ", standDev)
