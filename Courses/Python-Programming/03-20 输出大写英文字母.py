text = input()
found = []
for i in range(len(text)):
    if 'A' <= text[i] <= 'Z' and text[i] not in found:
        found.append(text[i])
        print(text[i], end='')
if len(found) == 0:
    print('Not Found')
