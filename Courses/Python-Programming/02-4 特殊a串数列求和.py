line = input().split()
a = int(line[0])
n = int(line[1])
s = 0
for i in range(1, n + 1):
    s = s * 10 + i * a
print("s = {}".format(s))
