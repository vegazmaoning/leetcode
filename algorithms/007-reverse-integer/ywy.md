```
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = 1 if x >0 else -1
        x = abs(x)
        x_reverse = str(x)[::-1]
        result = sign * int(x_reverse)
        if result < -2**31 or result > 2**31-1:
            return 0
        else:
            return result
```
