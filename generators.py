# Task 1-5: All generators
def square_generator(n):
    for i in range(n + 1):
        yield i**2

n = int(input("Enter N for squares: "))
print("Squares up to N:", list(square_generator(n)))

def even_generator(n):
    for i in range(0, n + 1, 2):
        yield str(i)

n2 = int(input("Enter N for even numbers: "))
print("Even numbers:", ", ".join(even_generator(n2)))