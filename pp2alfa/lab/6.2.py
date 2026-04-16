n = int(input())
nums = list(map(int, input().split()))

even_nums = filter(lambda x: x % 2 == 0, nums)
print(len(list(even_nums)))