data = list(map(int, input().split(' ')))
avg = sum(data) / len(data)
for number in data:
    if number > avg:
        print(number, end=' ')
