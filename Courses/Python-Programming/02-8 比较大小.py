line = input().split()
data = [int(i) for i in line]
data.sort()
print("{}->{}->{}".format(data[0], data[1], data[2]))
