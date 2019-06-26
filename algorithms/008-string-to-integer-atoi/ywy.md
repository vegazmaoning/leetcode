主要考虑边界： 0 个非空字符； 1个非空字符，一定要为数字； 大于1个非空字符，则第一个可为符号，之后的要为数字。

```
class Solution(object):
    def myAtoi(self, s):
        """
        :type str: str
        :rtype: int
        """
        sign = 1
        result = 0
        s = s.lstrip(' ')
        # len(s) = 0
        if len(s) == 0:
            return 0
        # len(s) == 1
        if len(s) == 1:
            if s[0] >= '0' and s[0] <= '9':
                return int(s[0])
            else:
                return 0
        # len(s) > 1
        if s[0] == '+':
            sign = 1
        elif s[0] == '-':
            sign = -1
        elif '0'<= s[0] and s[0] <= '9':
            result = int(s[0])
        else:
            return 0
        for i in s[1:]:
            if i >= '0' and i <= '9':
                result = result * 10 + int(i)
            else:
                if result == 0:
                    return 0
                else:
                    return max(min(sign * result, 2**31 -1), -2**31)
        return max(min(sign * result, 2**31-1), -2**31)
            
        
        
```
