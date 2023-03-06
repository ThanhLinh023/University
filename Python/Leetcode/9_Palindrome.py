def isPalindrome(a):
    if a < 0:
        return False
    else:
        t = [int(i) for i in str(a)]
        for i in range(int(len(t) / 2)):
            if t[i] != t[len(t) - 1 - i]:
                return False
        return True

print(isPalindrome(10))