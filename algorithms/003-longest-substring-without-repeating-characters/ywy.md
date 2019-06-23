一开始， 采用了双索引的方式，并对索引之间的数据做dict存储（key为字符，value为位置），方便查看是否重复。当有重复字符时，快速update子串的起始位置。
但是要refresh dict，后来看讨论才意识到只要判断这个重复字符的位置比我的起始位置靠前，就可以忽略掉，从而不用refresh字典。

边界条件是： 整个串没有重复字符， 或没有字符。
```
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        key_index = dict()
        start = 0
        max_len = 0
        for i in range(len(s)):
            if s[i] in key_index and start <= key_index[s[i]]:
                start = key_index[s[i]] + 1
            else:
                max_len = max(max_len, i-start+1)
            key_index[s[i]] = i
        return max_len

```
