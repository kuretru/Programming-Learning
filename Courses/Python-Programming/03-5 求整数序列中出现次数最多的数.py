data = list(map(int, input().split(' ')))
del data[0]
result = 0
for i in range(len(data)):
    if data.count(data[i]) > data.count(data[result]):
        result = i
print('{} {}'.format(data[result], data.count(data[result])))
