line = input().split()
result = 0
for i in range(2, int(line[1]) + 1, 2):
    result += int(line[0] * i)
print(result)
