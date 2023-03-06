def reverse(x):
    s = 0
    if x >= 0:
        while x > 0:
            k = x % 10
            s = s * 10 + k
            x //= 10
        if -2**31 <= s <= 2**31 - 1:
            return s
        else:
            return 0
    else:
        x = abs(x)
        while x > 0:
            k = x % 10
            s = s * 10 + k
            x //= 10
        if -2**31 <= s <= 2**31 - 1:
            return s * -1
        else:
            return 0
print(reverse(0))