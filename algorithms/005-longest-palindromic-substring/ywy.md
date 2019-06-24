动态规划解法：
  1. 最终目的：得到第 j -> i 子串为最长回文串
  2. 大事化小：找到第 j+1 -> i-1 子串为回文串，且第 j 个和第 i 个相同。考虑到边界条件，当 j+1 >= i-1，即 j >= i-2，也就是为 aba 或者 a 的情况。
  3. 代码实现：需要从小往上走，相当于利用空间缓存状态，减少大空间的计算量。
```
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        size = len(s)
        if len(s) <= 1:
            return s
        max_len = 1
        result = s[0]
        sqr = [[False for _ in range(size)] for _ in range(size)]
        
        for i in range(size):
            for j in range(i):
                if s[i] == s[j] and (sqr[j+1][i-1] or j+1 >= i-1):
                    sqr[j][i] = True
                    if i-j+1 > max_len:
                        max_len = i-j+1
                        result = s[j: i+1]
        return result
                    
```
