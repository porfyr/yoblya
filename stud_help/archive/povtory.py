vybir = int(input("Якщо бажаєте зчитувати з файлу введіть 1\nабо введіть 0 щоб зчитати з рядка\n> "))
s_in = str

if vybir == 1:
    f = open("text.txt", 'r')
    s_in = f.readline()
    f.close()
else:
    s_in = input()

s_res = ""
count = 0
for i in s_in:
    if i not in s_res and i != " ":
        s_res += i
    elif i == " ":
        s_res += "  "
        count += 1

vybir = int(input("Якщо бажаєте вивести результату файл введіть 1\nабо введіть 0 щоб вивести у консоль\n> "))
if vybir == 1:
    f = open("text.txt", "a")
    f.write('\n' + s_res)
    f.close()
else:
    print(s_res)