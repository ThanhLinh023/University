def removeElement(nums, val):
    for i in range(nums.count(val)):
        nums.remove(val)
    return len(nums)
t = removeElement([0,1,2,2,3,0,4,2], 2)
print(t)