```
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) == 0:
            return True
        table = {
            "(":")",
            "[": "]",
            "{": "}"
        }
        l = []
        for i in s:
            if i in table:
                l.append(table[i])
            else:
                if l:
                    tmp = l.pop()
                    print tmp
                    if tmp != i:
                        return False
                else:
                    return False
        return l == []

        
```
