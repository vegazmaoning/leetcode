在多行上将数据填充好，再经过concat返回结果。
关键时要考虑到 direction & position 这两个维度的特征
边界条件： position = row - 2;意味着如果 row = 1 要特殊处理

```
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        row = min(numRows, len(s))
        if row == 1:
            return s
        data = [[] for _ in range(row)]
        # 0 down / 1 up
        direction = 0 
        position = 0
        for i in s:
            data[position].append(i)
            if direction == 0:
                if position == row-1:
                    direction = 1
                    position = row-2
                else:
                    position += 1
            else:
                if position == 0:
                    direction = 0
                    position = 1
                else:
                    position -= 1

                
        result = ''            
        for row_data in data:
            result += ''.join(row_data)
        return result
```
