data = list(input())
for i in range(len(data)):
    if 'A' <= data[i] <= 'Z':
        data[i] = data[i].lower()
    elif 'a' <= data[i] <= 'z':
        data[i] = data[i].upper()
    elif '#' == data[i]:
        del data[i]
print(''.join(data))
