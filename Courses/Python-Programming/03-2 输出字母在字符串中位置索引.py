text = input()
keys = input().split(' ')
for key in reversed(keys):
    for i in range(len(text) - 1, -1, -1):
        if text[i] == key:
            print('{} {}'.format(i, key))
