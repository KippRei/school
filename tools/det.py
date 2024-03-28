size = int(input("Matrix Size: "))

matrix = [[0]*size for i in range(size)]

for i in range(size):
    for j in range(size):
        matrix[i][j] = int(input("a(" + str(i+1) + ", " + str(j+1) +"): "))

#Testing: comment out above, uncomment below
#matrix=[[-2,2,3,9],[1,2,2,3],[1,0,5,1],[-4,0,0,1]]
#matrix=[[-2,2,3],[1,2,3],[1,0,5]]

grandTotal = 0

def getDeterminant(mat):
    depth = len(mat)
    if depth == 2:
        det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0])
        return det
    else:
        total = 0
        for colVal in range(depth):
            newMat = [[0]*(depth-1) for i in range(depth-1)]
            currRow = -1
            currCol = -1
            for i in range(1, depth):
                currRow += 1
                currCol = -1
                for j in range(depth):
                    if j == colVal:
                        continue
                    currCol += 1
                    newMat[currRow][currCol] = mat[i][j]
                total += (((-1) ** (colVal)) * mat[0][colVal] * getDeterminant(newMat))
        return grandTotal + total     

# for i in range(matrix.count):
#     for j in range(matrix.count):
#         cofactorMatrix[i][j] = getDeterminant(i, j, matrix.count - 1)
    
print(getDeterminant(matrix))
