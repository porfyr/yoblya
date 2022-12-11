s_in = str(input())
s_res = ""
count = 0

for i in s_in:
    if i not in s_res and i != " ":
        s_res += i
    elif i == " ":
        s_res += "  "
        count += 1
print(s_res)