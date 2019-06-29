考虑到求的时 max(v(i,j)), v(i,j) = min(h[i], h[j]) * (j-i)
假设数据为 h = [1,2,5,3,6,8,3,4]
在双指针中，因为 1 < 4，于是将 i 从 0 -> 1 即 h[1]=2；那么对于后面的计算来说放弃了什么容器呢，为第 0 ～ 6 之间能够组成的容器。
但是这么多的容器的最大值，也比不上 0 - 7 组成的容器，所以记录上这个临时值用于后面的比较即可。

```
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        i = 0
        j = len(height) - 1
        v = 0 
        while i < j:
            v = max(v, min(height[i], height[j]) * (j-i))
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return v
        
```
