递归求
```
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        digits_map_char = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        if len(digits) == 0:
            return []
        if len(digits) == 1:
            return list(digits_map_char[digits[0]])

        tmp = self.letterCombinations(digits[1:])
        result = []
        for i in digits_map_char[digits[0]]:
            for t in tmp:
                result.append(i+t)
        return result
```
