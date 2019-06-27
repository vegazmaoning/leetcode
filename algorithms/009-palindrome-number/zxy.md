```
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        result = 0
        flag = x
        while flag:
            result = result * 10 + flag % 10
            flag /= 10
        return result == x
```
