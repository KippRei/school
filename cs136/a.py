key = int(input("key?: "))
buckets = 11
#bucketIn = input("bucket in?: ")
emptyBuckets = {1,2,4,5,7,8,9,10}
i = 0
b = False
while (not b):
    val = (key%buckets + i*(7-(key%7)))%buckets
    print(val)
    for j in emptyBuckets:
        if (val == j):
            b = True
            break
    i += 1

print("Num of checks= " + str(i-1))