```
创建一个与行数长度的列表，通过cursor控制将字符串赋值到哪个index下面，当index小于行数的时候，下一个字符就赋值给他的下一个元素，如果index到了numRows-1 则需要赋值给上一个元素，即cursor变为-1，如果赋值到了第一个元素，则往下赋值，cursor变为1。时间空间复杂度为O(n).主要是一个赋值的过程，根据不同位置，决定下一个值赋到哪个位置

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or len(s) <= numRows:
            return s
        result = ['' for i in range(numRows)]
        cursor = 1
        index = 0
        for char in s:
            result[index] = result[index] + char
            if index == numRows - 1:
                cursor = -1
            elif index == 0:
                cursor = 1
            index += cursor
        return ''.join(result)
        
```
