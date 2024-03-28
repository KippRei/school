# size = int(input("Matrix Size: "))

# matrix = [[0]*size for i in range(size)]

# for i in range(size):
#     for j in range(size):
#         matrix[i][j] = int(input("a(" + str(i+1) + ", " + str(j+1) +"): "))

##Testing: comment out above, uncomment below##
matrix=[[-2,2,3,9,-30],[1,2,2,-10,3],[1,0,.5,5,1],[-4,4,0,0,1],[1,-2,3,-4,5]]
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


def getCofactorMatrix(matrix):
    cofactorMatrix = [[0]*len(matrix) for i in range(len(matrix))]
    subMat = [[0]*(len(matrix)-1) for i in range(len(matrix)-1)]
    depth = len(matrix)
    
    for i in range(depth):
        for j in range(depth):
            rowIndex = -1
            colIndex = -1
            for row in range(depth):
                if row == i:
                    continue
                rowIndex += 1
                colIndex = -1
                for col in range(depth):
                    if col == j:
                        continue
                    colIndex += 1
                    subMat[rowIndex][colIndex] = matrix[row][col]
            cofactorMatrix[i][j] = ((-1) ** (i+j)) * getDeterminant(subMat)
    return cofactorMatrix

def transposeMatrix(matrix):
    tMat = [[0]*len(matrix) for i in range(len(matrix))]
    depth = len(matrix)
    for i in range(depth):
        for j in range(depth): 
            tMat[j][i] = matrix[i][j]
    return tMat

def prettyPrintMat(matrix):
    for row in matrix:
        print(row)

prettyPrintMat(transposeMatrix(getCofactorMatrix(matrix)))
