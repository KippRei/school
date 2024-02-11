#Generate quizzes from terms and definitions (input fmt = term-definition, term-definition,...)
import math, random

termDefList = input("Enter terms-definitions (seperated by '!!'): ").split("!!")
quizDict = {}
numOfTerms = 0

for termDef in termDefList:
    termDef = termDef.split("-")
    term = termDef[0]
    defi = termDef[1]
    quizDict.update({term: defi})
    numOfTerms += 1

questionNum = 0
while questionNum < numOfTerms:
    multiChoiceList = []
    cAns = questionNum
    print(list(quizDict.keys())[cAns] + ": ")
    correctPos = random.randint(0,3)

    for j in range(0, 4):
        if j == correctPos:
            multiChoiceList.insert(j, f"{j+1}. " + list(quizDict.values())[cAns])
        else: 
            randAns =  random.randint(0, numOfTerms - 1)
            multiChoiceList.insert(j, f"{j+1}. " + list(quizDict.values())[randAns])
        j += 1

    for item in multiChoiceList:
        print(item)

    answer = int(input("Answer: "))
    print(answer)
    print(correctPos)
    if answer == correctPos+1:
        print("Correct")
        print("")
    else:
        print("Incorrect")
        print("")

    questionNum += 1