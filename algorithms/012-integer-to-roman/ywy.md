其实就是一个贪婪算法，值得注意的就是将题目中说的特殊情况，如 4、 9 之类的也要考虑进去

```
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        result = ''
        while num:
            if num >= 1000: 
                num -= 1000; result += 'M'
            elif num >= 900:
                num -= 900; result += 'CM'
            elif num >= 500:
                num -= 500; result += 'D'
            elif num >= 400:
                num -= 400; result += 'CD'
            elif num >= 100:
                num -= 100; result += 'C'
            elif num >= 90:
                num -= 90; result += 'XC'
            elif num >= 50:
                num -= 50; result += 'L'
            elif num >= 40:
                num -= 40; result += 'XL'
            elif num >= 10:
                num -= 10; result += 'X'
            elif num >= 9:
                num -= 9; result += 'IX'
            elif num >= 5: 
                num -= 5; result += 'V'
            elif num >= 4:
                num -= 4; result += 'IV'
            elif num >= 1:
                num -= 1; result += 'I'
        return result
```
