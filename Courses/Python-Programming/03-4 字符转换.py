text = input()
number = ''
for i in range(len(text)):
    if '0' <= text[i] <= '9':
        number += text[i]
print(int(number))
