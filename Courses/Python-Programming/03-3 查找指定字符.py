key = input()
text = input()
index = text.rfind(key)
if index == -1:
    print("Not Found")
else:
    print("index = {}".format(index))
