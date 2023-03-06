def plusOne(digits):
    if len(digits) == 1:
        digits[0] += 1
        if digits[0] == 10:
            digits[0] = 1
            digits.append(0)
    else:
        tmp = 0
        for i in digits:
            tmp = tmp * 10 + i
        digits = [int(i) for i in str(tmp + 1)]
    return digits