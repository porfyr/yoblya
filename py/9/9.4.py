s = "sdvgsegedddddvte"
n = 1
n_res = 1
for i in range(len(s)-1):
    if s[i] == s[i+1]:
        n += 1
    else:
        if n > n_res:
            n_res = n
        n = 1

print(n_res)