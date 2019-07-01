```
首先将数组排序，然后用双指针一个指向循环元素后边的值，一个指向末尾，是的 a,b,c之和为0，如果大于0则大的左移，小于0 小的右移，考虑到元素重复作为同一个结果， 所以需要判断 左边的后一个，后边的前一个值是否相等，相等则直接跳过，如果后边的和前面的相等，直接跳出内存循环
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        for i in range(len(nums)):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                if i > 0 and nums[i] == nums[i-1]:
                    break
                cur_sum = nums[left] + nums[i] + nums[right]
                if cur_sum == 0:
                    result.append([nums[left], nums[i], nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1
                    left += 1
                    right -= 1
                elif cur_sum < 0:
                    left += 1
                else:
                    right -= 1
        return result
        
```
