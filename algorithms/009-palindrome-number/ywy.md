一开始忘了将 x 做一个副本来进行取余操作，导致 x 本身被改变，最后判断时出错。
```
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        y = x
        reverse = 0
        while y:
            remain = y % 10
            y = y / 10
            reverse = reverse*10 + remain
        return x == int(reverse)
        
```
