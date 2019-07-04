利用stack， 但空间复杂度为 O(n), 注意边界为，第一个字符就为 ‘)]}’
```
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        result = []
        for i in s:
            if i in {'(', '[', '{'}:
                result.append(i)
            else:
                if len(result) == 0:
                    return False
                if i == ')':
                    if result.pop() != '(':
                        return False
                elif i == ']':
                    if result.pop() != '[':
                        return False
                else:
                    if result.pop() != '{':
                        return False
                    
        return len(result) == 0
                        
        
```
