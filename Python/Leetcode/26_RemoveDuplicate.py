def removeDuplicates(nums):
    for i in nums:
        if nums.count(i) > 1:
            for j in range(nums.count(i) - 1):
                nums.remove(i)
    return len(nums)
t = removeDuplicates([0,0,1,1,1,2,2,3,3,4])
print(t)