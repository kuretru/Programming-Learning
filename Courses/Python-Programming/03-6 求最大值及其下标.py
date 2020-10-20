n = int(input())
data = list(map(int, input().split(' ')))
result = 0
for i in range(1, n):
    if data[i] > data[result]:
        result = i
print('{} {}'.format(data[result], result))
