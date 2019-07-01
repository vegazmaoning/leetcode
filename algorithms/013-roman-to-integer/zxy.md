```
优先判断两个的情况  如果不存在 就是一个  运用切片不会越界 所以不用考虑边界，只需要循环完就可以
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        table = {
            "I": 1,
            "IV": 4,
            "V": 5,
            "IX": 9,
            "X": 10,
            "XL": 40,
            "L": 50,
            "XC": 90,
            "C": 100,
            "CD": 400,
            "D": 500,
            "CM": 900,
            "M": 1000,
        }
        result, i = 0, 0
        while i <= len(s)-1:
            if s[i: i+2] in table:
                result += table[s[i: i+2]]
                i += 2
            else:
                result += table[s[i]]
                i += 1
        return result
        
```
