n = int(input())
a = []

for i in range(n):
    a.append(input())

count = 0

for x in a:
    if a.count(x) == 3:
        count += 1
        a = [y for y in a if y != x] 

print(count)
