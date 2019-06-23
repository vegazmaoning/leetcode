```
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = dict()
        start = 0
        length = 0
        for i in range(len(s)):
            if s[i] in result and result[s[i]] >= start:
                start = result[s[i]] + 1
            length = max(length, i - start +1)
            result[s[i]] = i
        return length
```
