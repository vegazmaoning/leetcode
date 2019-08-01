#主要还是通过递归来求解，选中迭代单元，从 1 ~ n ，然后对于左右两边的递归构造出所有可能的子树，然后组合在一起。能看懂，但是到真的做的时候，比较难想到这一点。。。

`
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        
        def generate_trees_by_range(start, end):
            if start > end:
                return [None]
            all_trees = []
            for i in range(start, end+1):
                left_trees = generate_trees_by_range(start, i-1)
                right_trees = generate_trees_by_range(i+1, end)
                
                for l in left_trees:
                    for r in right_trees:
                        tmp = TreeNode(i)
                        tmp.left = l
                        tmp.right = r
                        all_trees.append(tmp)
            return all_trees
        return generate_trees_by_range(1, n) if n > 0 else []
`
