n = int(input())
a = list(map(int, input().split()))

mx = a[0]       
pos = 1         

for i in range(1, n):
    if a[i] > mx:
        mx = a[i]
        pos = i + 1 

print(pos)
