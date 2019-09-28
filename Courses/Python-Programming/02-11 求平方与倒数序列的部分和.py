sum = 0.0
line = input().split()
m = int(line[0])
n = int(line[1])
for i in range(m, n + 1):
    sum += i * i + 1 / i
print("sum = {:.6f}".format(sum))
