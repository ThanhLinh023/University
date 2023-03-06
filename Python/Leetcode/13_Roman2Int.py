def romanToInt(st):
    sym = {"I" : 1, "V" : 5, "X" : 10, "L": 50, "C" : 100, "D" : 500, "M" : 1000}
    t = [i for i in str(st)]
    intNum = 0
    i = 0
    while i < len(t):
        if i < len(t) - 1:
            if t[i] == "I" and t[i + 1] == "V":
                intNum += 4
                i += 2
            elif t[i] == "I" and t[i + 1] == "X":
                intNum += 9
                i += 2
            elif t[i] == "X" and t[i + 1] == "L":
                intNum += 40
                i += 2
            elif t[i] == "X" and t[i + 1] == "C":
                intNum += 90
                i += 2
            elif t[i] == "C" and t[i + 1] == "D":
                intNum += 400
                i += 2
            elif t[i] == "C" and t[i + 1] == "M":
                intNum += 900
                i += 2
            else:
                intNum += sym[t[i]]
                i += 1
        else:
            intNum += sym[t[i]]
            i += 1
    return intNum
print(romanToInt("MCMXCIV"))