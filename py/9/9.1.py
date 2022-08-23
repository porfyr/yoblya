s = "Під мосто6м Міраб9о с3трумує4 Сена3"

d = dict()
for i in s:
    if i.isdigit():
        if int(i) in d:
            d[int(i)] += 1
        else:
            d[int(i)] = 1

print("Найбільше число =", max(d))

print("По 2 рази зустрічаються", [i for i in d if d[i] == 2])
