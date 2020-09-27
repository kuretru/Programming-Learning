import os

line = input().split()
lower = int(line[0])
upper = int(line[1])
if lower <= upper and upper <= 100:
    print("fahr celsius")
    for fahr in range(lower, upper + 1, 2):
        celsius = 5 * (fahr - 32) / 9
        print("{}{:6.1f}".format(fahr, celsius))
else:
    print("Invalid.")
