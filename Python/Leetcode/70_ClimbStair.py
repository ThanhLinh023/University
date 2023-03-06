def climbStair(n):
    t = [0, 1, 2]
    for i in range(3, 46):
        t.append(t[i - 1] + t[i - 2])
    return t[n]