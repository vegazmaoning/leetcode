```
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        area = 0
        left, right = 0, len(height) - 1
        while left < right:
            tmp_area = min(height[left], height[right]) * (right - left)
            area = max(area, tmp_area)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return area
```
