def main():
    p1 = input("Input P1 Genotype: ")
    p2 = input("Input P2 Genotype: ")
    comboArr = []

    if len(p1) != len(p2):
        print("Allele numbers must match")
        exit()

    geneLength = len(p1) / 2
    DebugPrint(geneLength)
    if geneLength % 1 != 0:
        print("Improper allele length")
        exit()

    #combine sections of alleles (2 at a time) and combine into arrays
    i = 0
    while i < geneLength * 2:
        temp = []
        for j in range(i, i+2):
            for k in range(i, i+2):
                temp.append(p1[j] + p2[k])
        comboArr.append(temp) 
        i += 2

    i = 0
    f1Arr = []
    iterArr = comboArr
    numInComboArr = len(comboArr)
    numOfItemsInF1Arr = 2

    # loop: multiplies genes two at a time (creating arrays) until there is one array remaining
    # i.e. AABBCCDD + aabbccdd => first loop [['AABB', 'AABb', 'AAbB', 'AAbb', 'AaBB', 'AaBb', 'AabB', 'Aabb', 'aABB', 'aABb', 'aAbB', 'aAbb', 'aaBB', 'aaBb', 'aabB', 'aabb']] \
    # second (final) loop [['AABB', 'AABb', 'AAbB', 'AAbb', 'AaBB', 'AaBb', 'AabB', 'Aabb', 'aABB', 'aABb', 'aAbB', 'aAbb', 'aaBB', 'aaBb', 'aabB', 'aabb']]

    while numOfItemsInF1Arr > 1:
        f1Arr = []
        numInComboArr = len(iterArr)
        i = 0

        while i < len(iterArr) - 1:
            f1TempArr = []
            tempArr = iterArr[i]
            for a in range(0,len(iterArr[i])):
                aVal = tempArr[a]
                for b in range(0,len(iterArr[i+1])):
                    f1TempArr.append(aVal + iterArr[i+1][b])
            f1Arr.append(f1TempArr)
            i += 2

        if i == numInComboArr - 1:
            f1Arr.append(iterArr[i])
        
        iterArr = f1Arr
        DebugPrint(iterArr)
        numOfItemsInF1Arr = len(iterArr)
        DebugPrint(numOfItemsInF1Arr)

    DebugPrint(["final", f1Arr])
    DebugPrint(len(f1Arr[0]))

    # convert final array into list for easier use
    tempFinalList = []
    for item in f1Arr[0]:
        tempFinalList.append(item)


    finalList = [] #ensures normalized casing (e.g. aA ->(case switch) Aa)
    for it in tempFinalList:
        g = 0
        itList = list(it)
        while g < len(it) - 1:
            if itList[g].islower() and itList[g+1].isupper():
                itList[g] = itList[g].upper()
                itList[g+1] = itList[g+1].lower()
            g += 2
        DebugPrint(itList)
        newIt = ''.join(itList)
        finalList.append(newIt)


    finalCount = {} #dict to store key val pairs of alleles:count
    while len(finalList) > 0:
        itemToCheck = finalList.pop(0)
        if itemToCheck in finalCount:
            finalCount[itemToCheck] += 1
        else:
            finalCount[itemToCheck] = 1

    DataCalc(finalCount)


def DataCalc(data):
    print("F1 Genotype:")
    DictPrint(data)

    print("F1 Phenotype: ")
    alleleLength = len(list(data.keys())[0]) #get length of allele
    phenoDict = {} #dict to store key val pairs of phenotypes
    for key, val in data.items():
        i = 0
        phenoKey = ""
        while i < alleleLength:
            phenoKey += key[i]
            i += 2
            
        if phenoKey in phenoDict:
            phenoDict[phenoKey] += val
        else:
            phenoDict[phenoKey] = val

    DictPrint(phenoDict)


def DictPrint(dict):
    strToPrint = ""
    for key, val in dict.items():
        strToPrint += str(val) + " " + str(key) + "\n"
    print(strToPrint)


def DebugPrint(toPrint):
    #print(toPrint)
    return


main()