```
将情况列出来  需要特殊考虑 带 4 9的数字 
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        integer = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        roman = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V','IV', 'I']
        result = ""
        for index, value in enumerate(integer):
            remainder = num / value
            result += roman[index] * remainder
            num -= remainder * value
            if num == 0:
                return result
```
