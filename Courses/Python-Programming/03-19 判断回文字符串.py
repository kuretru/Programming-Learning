text = input()
reversed_text = list(text)
reversed_text.reverse()
reversed_text = ''.join(reversed_text)
print(text)
if text == reversed_text:
    print('Yes')
else:
    print('No')
