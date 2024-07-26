u1 = float(input("u1:"))
u2 = float(input("u2:"))
u3 = float(input("u3:"))
v1 = float(input("v1:"))
v2 = float(input("v2:"))
v3 = float(input("v3:"))

i = (u2 * v3) - (u3 * v2)
j = -1 * ((u1 * v3) - (u3 * v1))
k = (u1 * v2) - (u2 * v1)

print("(",i,",",j,",",k,")")