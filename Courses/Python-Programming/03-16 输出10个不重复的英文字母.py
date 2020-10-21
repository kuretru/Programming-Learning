text = input()
exists = []
result = []
for i in range(len(text)):
    if text[i].isalpha() and len(exists) < 10 and text[i].lower() not in exists:
        exists.append(text[i].lower())
        result.append(text[i])
if len(exists) < 10:
    print('not found')
else:
    print(''.join(result))
