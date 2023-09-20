import math

volume = [5.0,10.0,15.0,20.0]
mass = []
moles = []
moleFrac = []
molPropanol = (20*.805)/60.1
for i in volume:
    mass.append(float(i)*.7866)
for i in mass:
    moles.append(i/32.04)
for i in moles:
    moleFrac.append(i/(i+molPropanol))

solPress = float(input("Enter Mixture Pressure: "))
measPress = input("Enter Measured Pressures: ")
measPress = measPress.split(",")
purePress = []
for i in measPress:
    # Determine pressure of methanol
    purePress.append(float(i) - solPress)

averagePress = 0
n = 0
methanolPressure = []
for i, j in zip(purePress, moleFrac):
    methanolPressure.append(i / j)
    averagePress += (i/j)
    n += 1

average = averagePress / n
stdDev = 0
for i in methanolPressure:
    stdDev += abs(i - average)
stdDev = (stdDev * 100) / (n * average) 

print("Mass | Moles | Mole Fraction | Exp Pressure")
for mass, mole, molef, exppress in zip(mass, moles, moleFrac, methanolPressure):
    print(mass, " ", mole, " ", molef, " ", exppress)
print("Average = ", average)
print("Percent Relative Standard Deviation = ", stdDev)