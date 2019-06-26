```
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        pattern = re.compile(r"^([-+]?\d+)")
        ret = pattern.match(str.strip())
        num = 0
        flag = 1
        if ret:
            result = ret.groups()[0]
            if result[0] == "-":
                flag = -1
                num = int(''.join(result[1:]))
            else:
                flag = 1
                num = int(''.join(result))
        if num * flag > 2 ** 31 -1:
            return 2 ** 31 -1
        elif num * flag < -2 ** 31:
            return -2 ** 31
        else:
            return num * flag

```
