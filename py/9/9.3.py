s = "aadbmdvscc"
s_new = []
for i in range(len(s)-1):
    if s[i] != s[i+1]:
        s_new.append(s[i])
s_new.append(s[-1])
print("".join(s_new))