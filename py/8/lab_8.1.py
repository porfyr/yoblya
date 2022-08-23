def print_m(mx):
    print("\nМатриця:\n")
    for h in mx:
        print(h)

def genMatrix(height, width, mode):
    mx = []
    if mode == 1:
        for h in range(height):
            row = input().split()[:width]       # Введення чисел через пробіли!
            for w in range(len(row)):
                row[w] = int(row[w])
            #print(row)
            mx.append(row)
    else:                       # рандомний генератор матриці
        import random
        for h in range(height):
            row = []
            for w in range(width):
                row.append(random.randint(0, 9))
            mx.append(row)
    return mx

def get_sidlovi(mx):
    indexes = []
    for h in mx:
        for w in h:
            if w == min(h):
                is_sidlovyi = True
                for i in range(len(mx)):
                    if mx[i][h.index(w)] > w:
                        is_sidlovyi = False
                if is_sidlovyi == True:
                    indexes.append([mx.index(h), h.index(w)])
    return indexes


h = int(input("Висота матриці: "))
w = int(input("Ширина матриці: "))
mx = genMatrix(h, w, 1)
print_m(mx)
# mx = [
#     [1, 2, 3, 4],
#     [3, 5, 6, 7],
#     [2, 5, 6, 3],
#     [3, 5, 8, 2]
# ]
print("\nІндекси сідлових елементів\n", get_sidlovi(mx))