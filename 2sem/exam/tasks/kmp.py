a = "образ"


# Этап 1
p = [0] * len(a)

j = 0
i = 1

while i < len(a):
    if a[j] == a[i]:
        p[i] = j + 1
        i += 1
        j += 1
    else:
        if j == 0:
            p[i] = 0
            i += 1
        else:
            j = p[j - 1]


# Этап 2
a = "строка"
t = "образ"

i = 0
j = 0

m = len(t)
n = len(a)

if a[i] == t[j]:
    i += 1
    j += 1
    if i == m:
        print("Образ найден")
    else:
        if j > 0:
            j = p[j - 1]
        else:
            i += 1
            if i == n:
                print("Образ не найден")

