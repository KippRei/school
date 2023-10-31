p1 = input("Input P1 Genotype: ")
p2 = input("Input P2 Genotype: ")
comboArr = []


if len(p1) != len(p2):
    print("Allele numbers must match")
    exit()

geneLength = len(p1) / 2

if geneLength != 1 and geneLength % 2 != 0:
    print("Improper allele length")
    exit()

#combine sections of alleles (2 at a time) and combine into arrays
i = 0
while i <= geneLength:
    temp = []
    for j in range(i, i+2):
        for k in range(i, i+2):
             temp.append(p1[j] + p2[k])
    comboArr.append(temp) 
    i += 2

print(comboArr)

i = 0

while i < len(comboArr):
    print