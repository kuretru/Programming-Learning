denominator = 1
sum = 0.0
N = int(input())
for i in range(N):
    sum += 1 / denominator
    denominator += 2
print("sum = {:.6f}".format(sum))
