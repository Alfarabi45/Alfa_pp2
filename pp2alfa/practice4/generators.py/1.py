# 1️⃣ Squares up to N
def square_generator(n):
    for i in range(n + 1):
        yield i * i


n = int(input("1) Enter N for squares up to N: "))
print("Squares up to N:")
for value in square_generator(n):
    print(value)

print("----------------------")


# 2️⃣ Even numbers from 0 to n (comma separated)
def even_numbers(n):
    for i in range(n + 1):
        if i % 2 == 0:
            yield i


n = int(input("2) Enter n for even numbers: "))
print("Even numbers:")
print(",".join(str(num) for num in even_numbers(n)))

print("----------------------")


# 3️⃣ Numbers divisible by 3 and 4
def divisible_by_3_and_4(n):
    for i in range(n + 1):
        if i % 12 == 0:
            yield i


n = int(input("3) Enter n for numbers divisible by 3 and 4: "))
print("Numbers divisible by 3 and 4:")
for num in divisible_by_3_and_4(n):
    print(num)

print("----------------------")


# 4️⃣ Squares from a to b
def squares(a, b):
    for i in range(a, b + 1):
        yield i * i


a = int(input("4) Enter a: "))
b = int(input("   Enter b: "))
print("Squares from a to b:")
for value in squares(a, b):
    print(value)

print("----------------------")


# 5️⃣ Countdown from n to 0
def countdown(n):
    while n >= 0:
        yield n
        n -= 1


n = int(input("5) Enter n for countdown: "))
print("Countdown:")
for num in countdown(n):
    print(num)