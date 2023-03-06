def commonPrefix(strs):
    ref = strs.pop()
    for i in range(len(ref)):
        for item in strs:
            if i>=len(item) or item[i]!=ref[i]:
                if i==0:
                    return ""
                return ref[0:i]
    return ref
print(commonPrefix(["flower","fly", "fla"]))