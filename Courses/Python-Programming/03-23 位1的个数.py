number = str(bin(int(input())))
count = 0
for i in range(len(number)):
    if number[i] == '1':
        count += 1
print(count)
