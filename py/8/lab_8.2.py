from ctypes.wintypes import HWINSTA


def print_m(mx):
    print("\nМатриця:\n")
    for h in mx:
        print(h)

def genMatrix(hw, mode):
    mx = []
    if mode == 1:
        for h in range(hw):
            row = input().split()[:hw]       # Введення чисел через пробіли!
            for w in range(len(row)):
                row[w] = int(row[w])
            #print(row)
            mx.append(row)
    else:                       # рандомний генератор матриці
        import random
        for h in range(hw):
            row = []
            for w in range(hw):
                row.append(random.randint(0, 9))
            mx.append(row)
    return mx

def mult_m(mx1, mx2):
    length = len(mx1) 
    result_matrix = [[0 for i in range(length)] for i in range(length)]
    for i in range(length):
      for j in range(length):
        for k in range(length):
           result_matrix[i][j] += mx1[i][k] * mx2[k][j]
    return result_matrix

hw = int(input("Висота й ширина матриці: "))
mx1 = genMatrix(hw, 0)
mx2 = genMatrix(hw, 0)
print_m(mx1)
print_m(mx2)
print_m(mult_m(mx1, mx2))
