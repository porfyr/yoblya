import random

def simp(k):
    if k > 1:
        for i in range(2, int(k/2)+1):
            if (k % i) == 0:
                return False
                break
            else:
                return True
    else:
        return False

nat = sorted([random.randint(0, 20) for i in range(20)])

n = 0
for i in nat:
    if simp(i):
        n +=1
print(n)