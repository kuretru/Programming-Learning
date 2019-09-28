import math

line = input().split()
a = int(line[0])
b = int(line[1])
c = int(line[2])
if a + b > c and a + c > b and b + c > a:
    s = (a + b + c) / 2
    area = math.sqrt(s * (s - a) * (s - b) * (s - c))
    print("area = {:.2f}; perimeter = {:.2f}".format(area, a + b + c))
else:
    print("These sides do not correspond to a valid triangle")
