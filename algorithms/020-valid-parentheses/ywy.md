利用stack， 但空间复杂度为 O(n)
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
