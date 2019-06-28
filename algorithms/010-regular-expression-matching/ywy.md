这题一开始的时候看到解析思路为
1. 对于 * 符号，做匹配 0 次 / 匹配 1 次这两种情况拆解，最佳子结构式子为：isMatch(s, p[2:]), isMatch(s[1:], p)
2. 对于无 * 符号，就正常匹配即可，最佳子结构式子为：p[0] in {s[0], '.'}, isMatch(s[1:], p[1:])

对 p 的情况进行分析，边界为长度为 0 / 1

一开始写的很复杂的代码，主要是判断了 s 的长度，其实可以直接将其合并， self.isMatch(s, p[2:]) or len(s) and ...

```
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if len(p) == 0: return len(s) == 0
        if len(p) == 1: return len(s) == 1 and p[0] in {s[0], '.'}
        if p[1] == '*':
            # 1. * means zero
            # 2. * means one or multi
            
            if len(s) == 0:
                return self.isMatch(s, p[2:])

            return self.isMatch(s, p[2:]) or ( p[0] in {s[0], '.'} and self.isMatch(s[1:], p))
        else:
            if len(s) == 0:
               return False
            return p[0] in {s[0], '.'} and self.isMatch(s[1:], p[1:])
```


进行合并后，优化了判断结构

```
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if not p:
            return not s
        if len(p) == 1:
            return len(s) > 0 and p[0] in {s[0], '.'} and self.isMatch(s[1:], p[1:])
        if len(p) >= 2:
            if p[1] == '*':
                return self.isMatch(s, p[2:]) or len(s) > 0 and p[0] in {s[0], '.'} and self.isMatch(s[1:], p)
            else:
                return len(s) > 0 and p[0] in {s[0], '.'} and self.isMatch(s[1:], p[1:])
```


类似于 Fibonacci 数组，如果通过递归来计算，由于编译器不会帮我们做重复路径的存储，
所以我们每次计算出一个值，都手动的存储起来，每次用的时候先看缓存中有没有，有就直接取，没有就计算。
区别在于，Fibonacci 数列可以自底向上来计算，从 F(0) 开始循环直到 F(N)，而对于本问题，还是自顶向下的，只不过缓存了数据


```
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        mem = {}
        def f(i, j):
            if (i, j) in mem: return mem[(i, j)]
            if j == len(p): 
                return i == len(s)
            tmp = i < len(s) and p[j] in {s[i], '.'}
            
            if j < len(p) - 1 and  p[j+1] == '*':
                ans = f(i, j+2) or tmp and f(i+1, j)
            else:
                ans = tmp and f(i+1, j+1)
            mem[(i,j)] = ans
            return ans
                
        return f(0, 0)

    
```
