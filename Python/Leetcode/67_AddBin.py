def addBin(a, b):
    n = max(len(a), len(b))
    a = a.zfill(n + 1)
    b = b.zfill(n + 1)
    carry = 0
    result = ""
    for i in range(len(a) - 1, -1, -1):
        t = int(a[i]) + int(b[i]) + carry
        if t > 0:
            if t % 2 == 0:
                carry = 1
                result += "0"
            else:
                carry = 0
                if t == 3:
                    carry = 1
                result += "1"
        else:
            result += "0"
    result = result[::-1]
    if result[0] == "0":
        return result[1::]
    else:
        return result
print(addBin("0", "0"))