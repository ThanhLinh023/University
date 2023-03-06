def merge(nums1, m, nums2, n):
    if m == 0:
        for i in range(len(nums1)):
            nums1.pop()
        if n != 0:
            for i in range(n):
                nums1.append(nums2[i])
    else:
        for i in range(m, len(nums1)):
            nums1.pop()
        for i in range(n):
            nums1.append(nums2[i])
    nums1.sort()
l1 = [0,0,0,0,0]
m = 0
l2 = [1,2,3,4,5]
n = 5
merge(l1,m,l2,n)
print(l1)