number = input()
result = 0
for i in range(len(number)):
    result += int(number[i])
print('{} {}'.format(len(number), result))
