line = input().split()
a = int(line[0])
b = int(line[1])
sum = 0
for i, j in zip(range(a, b + 1), range(b + 1 - a)):
    print("{:5d}".format(i), end="")
    if j % 5 == 4 or i == b:
        print()
    sum += i
print("Sum = {}".format(sum))
