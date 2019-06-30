```
找出最短字符串，然后进行比较 时间复杂度 len(min_len) * len(strs)   应该不是最优解
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        length_list = [len(s) for s in strs]
        min_str = strs[length_list.index(min(length_list))]
        for index, value in enumerate(min_str):
            for s in strs:
                if s[index] != value:
                    if index == 0:
                        return ""
                    return strs[0][:index]
        return min_str

        
```
