WEIGHTS = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
M = ['1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2']

count = int(input())
all_passed = True
for i in range(count):
    text = input()
    sums = 0
    for j in range(17):
        if not text[j].isnumeric():
            sums = -1
            break
        sums += int(text[j]) * WEIGHTS[j]
    if sums == -1 or M[sums % 11] != text[17]:
        all_passed = False
        print(text)
if all_passed:
    print('All passed')
