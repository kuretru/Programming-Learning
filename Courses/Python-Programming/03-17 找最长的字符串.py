count = int(input())
max_length = 0
result = ''
for i in range(count):
    text = input()
    if len(text) > max_length:
        max_length = len(text)
        result = text
print('The longest is: ' + result)
