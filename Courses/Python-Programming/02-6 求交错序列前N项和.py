sum = 0.0
N = int(input())
for i in range(1, N + 1):
    if i % 2 == 1:
        sum += i / (i * 2 - 1)
    else:
        sum -= i / (i * 2 - 1)
print("{:.3f}".format(sum))
