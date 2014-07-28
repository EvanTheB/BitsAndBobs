test = [1,'cat',2.0,25]
print(test)
b = test*2
c = [test]*2
print(b)
print(c)
test.pop(3)
print(b)
print(c)
#print(test.sort())


#dictionaries
print('dict')
testd = {}
testd['key'] = 'value'
testd[5] = 10
print(testd)
print(testd.keys())
print(testd.values())
