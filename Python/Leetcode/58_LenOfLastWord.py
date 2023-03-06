def lengthOfLastWord(s):
    s = s.strip()
    if len(s) == 1:
        return 1
    t = ""
    for i in range(len(s) - 1, -1, -1):
        if 'A' <= s[i] <= 'Z' or 'a' <= s[i] <= 'z':
            t = t + s[i]
        else:
            break
    return len(t)
print(lengthOfLastWord("     day"))