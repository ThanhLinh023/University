from operator import index
def searchInsert(nums, target):
    if target in nums:
        return nums.index(target)
    else:
        nums.append(target)
        nums.sort()
        return nums.index(target)
print(searchInsert([1,3,5,6], 7))