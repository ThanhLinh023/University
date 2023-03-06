def addTwoNumbers(l1, l2):
    ans = []
    if len(l1) == len(l2):
        for i in range(len(l1)):
            res = 0
            t = l1[i] + l2[i]
            if t >= 10:
                res = int(t / 10)
                t = t % 10
                if i == len(l1) - 1:
                    l1.append(0)
                    ans.append(t)
                    ans.append(res)
                    break
                else:
                    l1[i + 1] += res
            ans.append(t)
    elif len(l1) > len(l2):
        for i in range(len(l1) - len(l2)):
            l2.append(0)
        for i in range(len(l1)):
            res = 0
            t = l1[i] + l2[i]
            if t >= 10:
                res = int(t / 10)
                t = t % 10
                if i == len(l1) - 1:
                    l1.append(0)
                    ans.append(t)
                    ans.append(res)
                    break
                else:
                    l1[i + 1] += res
            ans.append(t)
    else:
        for i in range(len(l2) - len(l1)):
            l1.append(0)
        for i in range(len(l1)):
            res = 0
            t = l1[i] + l2[i]
            if t >= 10:
                res = int(t / 10)
                t = t % 10
                if i == len(l1) - 1:
                    l1.append(0)
                    ans.append(t)
                    ans.append(res)
                    break
                else:
                    l1[i + 1] += res
            ans.append(t)
    return ans
l1 = [9,9,9,4,2,3,6,1] 
l2 = [9,9,9,0,2,4,1]
m = addTwoNumbers(l1, l2)
print(m)