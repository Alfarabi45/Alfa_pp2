n = int(input())

prime = True

for i in range(2, n):
    if n % i == 0:
        prime = False

if n > 1 and prime:
    print("Yes")
else:
    print("No")
