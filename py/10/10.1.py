eq = "x**2-x*4+2=0"
a = 1
next_inx = 4
if eq[0] != "-":
    if eq[4] == "*":
        inx = 4
        n_str = ""
        while True:
            inx += 1
            if eq[inx].isdigit():
                n_str += eq[inx]
            else:
                next_inx = inx
                break
        a = int(n_str)
else:
    a = -1
    if eq[5] == "*":
        inx = 5
        n_str = ""
        while True:
            inx += 1
            if eq[inx].isdigit():
                n_str += eq[inx]
            else:
                next_inx = inx
                break
        a = -int(n_str)
print("a =", a)

b = 1
n_dir = eq[next_inx]
next_inx += 2
if eq[next_inx] == "*":
    inx = next_inx
    n_str = ""
    while True:
        inx += 1
        if eq[inx].isdigit():
            n_str += eq[inx]
        else:
            next_inx = inx
            break
    b = int(n_str)
    if n_dir == "-":
        b *= -1
print("b =", b)

c = 1
n_dir = eq[next_inx]
if n_dir == "=":
    c = 0
else:
    inx = next_inx
    n_str = ""
    while True:
        inx += 1
        if eq[inx].isdigit():
            n_str += eq[inx]
        else:
            next_inx = inx
            break
    c = int(n_str)
    if n_dir == "-":
        c *= -1
print("c =", c)

rh = float(b**2 - 4 * a * c)
if rh < 0:
    print("Рівняння розв'язку не має")
else:
    r = rh ** (1/2)
    x1 = round((-b + r)/2, 2)
    x2 = round((-b - r)/2, 2)

    print("Розв'язки рівняння", x1, x2)