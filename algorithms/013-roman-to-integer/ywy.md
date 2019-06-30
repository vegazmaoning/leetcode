简单的说就是依次匹配的过程，看特殊情况是否匹配，再看从大开始是否匹配。 
边界条件是： 最后是剩了一个还是没有剩
```
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000, 'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM':900
        }
        i = 0
        result = 0
        while i < len(s) - 1:
            if s[i:i+2] in m:
                result += m[s[i:i+2]]
                i += 2
            else:
                result += m[s[i]]
                i += 1
        if i == len(s) - 1:
            result += m[s[i]]
        return result
```
