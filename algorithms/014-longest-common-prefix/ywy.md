依次比较第一个元素是否一样，否则返回之前的前缀

```
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ''
        strs = [list(s) for s in strs]
        first = ''.join(strs[0])
        for i in range(len(first)):
            for j in strs[1:]:
                if not len(j): return first[:i]
                if j[0] != first[i]:
                    return first[:i]
                else:
                    j.pop(0)


        return first
```
