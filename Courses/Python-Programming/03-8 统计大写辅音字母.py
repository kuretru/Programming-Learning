text = input()
result = 0
for c in text:
    if 'A' <= c <= 'Z' and c not in ['A', 'E', 'I', 'O', 'U']:
        result += 1
print(result)
