to_digit = {
    "ZER": "0", "ONE": "1", "TWO": "2",
    "THR": "3", "FOU": "4", "FIV": "5",
    "SIX": "6", "SEV": "7", "EIG": "8",
    "NIN": "9"
}

to_word = {v: k for k, v in to_digit.items()}

def decode(s):
    return int("".join(to_digit[s[i:i+3]] for i in range(0, len(s), 3)))

def encode(num):
    return "".join(to_word[d] for d in str(num))

expr = input()

for op in "+-*":
    if op in expr:
        left, right = expr.split(op)
        break

a = decode(left)
b = decode(right)

if op == "+":
    result = a + b
elif op == "-":
    result = a - b
else:
    result = a * b

print(encode(result))
