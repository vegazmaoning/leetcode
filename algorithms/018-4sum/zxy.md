```
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        length = len(nums)
        result = []
        for i in range(length - 3):
            if i >=1 and nums[i] == nums[i-1]:
                continue
            if nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target:
                break
            for j in range(i+1, length-2):
                if j - i > 1 and nums[j] == nums[j-1]:
                    continue
                if nums[i] + nums[j] + nums[length-2] + nums[length-1] < target:
                    continue
                left = j +1
                right = length -1
                while left < right:
                    if nums[i] + nums[j] + nums[left] + nums[right] == target:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        while left < right and nums[left] == nums[left+1]:
                            left += 1
                        while left < right and nums[right] == nums[right-1]:
                            right -= 1
                        left += 1
                        right -= 1
                    elif nums[i] + nums[j] + nums[left] + nums[right] < target:
                        left +=1
                    else:
                        right -= 1
        return result
        
```
