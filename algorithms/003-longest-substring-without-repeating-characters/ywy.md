一开始， 采用了双索引的方式，并对索引之间的数据做dict存储（key为字符，value为位置），方便查看是否重复。当有重复字符时，快速update子串的起始位置。
但是要refresh dict，后来看讨论才意识到只要判断这个重复字符的位置比我的起始位置靠前，就可以忽略掉，从而不用refresh字典。

边界条件是： 整个串没有重复字符， 或没有字符。

```
# 每次有重复字符refresh 字典的方式
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        i = 0
        while i< len(s):
            key_map_index = dict()    
            j = i
            while j < len(s):
                if s[j] not in key_map_index:
                    key_map_index[s[j]] = j
                    j += 1
                else:
                    count = max(count, len(key_map_index))
                    break
            if j == len(s):
                return max(count, len(key_map_index))
            else:
                i = key_map_index[s[j]] + 1
        return count
```



```
# 根据重复字符的inde与初始位置比较来避免refresh
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
