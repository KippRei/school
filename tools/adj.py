size = int(input("Matrix Size: "))

matrix = [[0]*size for i in range(size)]

for i in range(size):
    for j in range(size):
        matrix[i][j] = input("a(" + str(i) + ", " + str(j) +"): ")

