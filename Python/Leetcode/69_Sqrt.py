def mySqrt(x):
    count = 0
    i = 1
    while x > 0:
        count += 1
        x -= i
        i += 2
        if x < i:
            break
    return count
print(mySqrt(25))