import timeit

toTest = '''  
i = 0  
while i < 1000:
        print(i**2)
        i += 1'''

print(timeit.timeit(stmt=toTest, number=10000))