#将二叉树分成2段，选中 i 为根节点，那么 1~i-1 为左子树，i+1~n 为右子树，排列组合得到最终结果


`

class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        mem = {}
        mem[0] = 1
        mem[1] = 1
        
        def helper(k):
            if k in mem: return mem[k]
            count_k = 0
            i = 1
            while i <= k:
                count_i_1 = mem[i-1] if i-1 in mem else helper(i-1)
                count_k_i = mem[k-i] if k-i in mem else helper(k-i)
                count_k += helper(i-1) * helper(k-i)
                i += 1
            mem[k] = count_k
            return count_k
        
        return helper(n)
`
