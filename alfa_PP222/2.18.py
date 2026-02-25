n = int(input())
a = []

for i in range(n):
    a.append(input())

used = []

for s in sorted(a):
    if s not in used:
        print(s, a.index(s) + 1)
        used.append(s)
