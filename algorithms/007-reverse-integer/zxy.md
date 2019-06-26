```
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        flag = 1 if x >= 0 else -1
        result = 0
        x = x * flag
        while x:
            result *= 10
            result += x % 10
            x /= 10
        return result * flag if  (-2 ** 31) < result * flag < (2 ** 31 -1) else 0
```
