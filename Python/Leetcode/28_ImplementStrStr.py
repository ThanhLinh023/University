def strStr(haystack: str, needle: str) -> int:
    # if len(needle) == 0 or haystack == needle:
    #     return 0
    # if len(needle) == 1:
    #     for i in range(len(haystack)):
    #         if haystack[i] == needle:
    #             return i
    # else:
    #     for i in range(len(haystack)):
    #         k = 0
    #         while True:
    #             sub = haystack[i : k]
    #             if sub == needle:
    #                 return i
    #             else:
    #                 k += 1
    #                 if k == len(haystack) + 1:
    #                     break
    # return -1
    if len(needle) == 0:
        return 0
    elif needle in haystack:
        return haystack.index(needle)
    else:
        return -1
print(strStr("mississippi", "pi"))