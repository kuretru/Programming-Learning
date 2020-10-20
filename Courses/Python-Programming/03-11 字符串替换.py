OLD_KEYS = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')
NEW_KEYS = list('ZYXWVUTSRQPONMLKJIHGFEDCBA')
text = list(input())
for i in range(len(text)):
    for j in range(26):
        if text[i] == OLD_KEYS[j]:
            text[i] = NEW_KEYS[j]
            break
print(''.join(text))
