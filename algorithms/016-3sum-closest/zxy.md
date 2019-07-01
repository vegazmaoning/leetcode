```
思路基本与三数之和相同， 如果当前的差的绝对值 小于之前的 则交换。循环的时候  如果当前和大于target则 往小了走， 反之 往大了走
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        result = nums[0] + nums[1] + nums[2]
        for i in xrange(len(nums)):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                if i > 0 and nums[i] == nums[i-1]:
                        break
                cur_sum = nums[left] + nums[i] + nums[right]
                if abs(target - cur_sum) < abs(target - result):
                    result = cur_sum
                if target < cur_sum :
                    right -= 1
                elif target > cur_sum:
                    left += 1
                else:
                    return result
        return result
```
