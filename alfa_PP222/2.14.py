n = int(input())
a = list(map(int, input().split()))

best = a[0]
max_count = 0

for x in a:
    c = a.count(x)
    if c > max_count or (c == max_count and x < best):
        max_count = c
        best = x

print(best)
