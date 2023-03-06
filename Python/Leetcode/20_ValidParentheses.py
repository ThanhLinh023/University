def isValid(s):
    t = []
    for i in range(len(s)):
        if s[i] == '(' or s[i] == '[' or s[i] == '{':
            t.append(s[i])
        elif s[i] == ')':
            t.remove('(')
        elif s[i] == ']':
            t.remove('[')
        else:
            t.remove('{')
    if len(t) == 0:
        return True
    return False
print(isValid("[()]"))