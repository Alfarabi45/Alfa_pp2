def sum_numbers(*nums):
    return sum(nums)
nums = list(map(int, input().split()))

print(sum_numbers(nums))