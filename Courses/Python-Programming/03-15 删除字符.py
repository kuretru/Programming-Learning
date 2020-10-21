text = input().strip()
key_up = input().strip().upper()
key_low = key_up.lower()
print('result: ', end='')
for i in range(len(text)):
    if text[i] == key_up or text[i] == key_low:
        continue
    print(text[i], end='')
