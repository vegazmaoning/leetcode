# 第一种办法是，通过递归来实现。在树中很多操作都可以考虑用递归，所以关键是要找到基本的模式是什么，在这个题目中，基本的模式是，所有的节点都要先打印左子节点，然后时父节点，最后是右子节点。所以在满足边界条件下进行递归调用。

`
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
       
        
        def helper(node, res_list):
            if node is not None:
                helper(node.left, res)
                res.append(node.val)
                helper(node.right, res)
        
        res = []
        helper(root, res)
        return res 


`
# 第二种方法，是通过迭代的方式进行求解。具体表现为，从根节点依次遍历左子节点，并记录待会儿还要确认右子节点的父节点。当节点没有左子节点的时候，再看右子节点的子节点情况。最终把记录中的所有节点检查完。

`

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        stack = []
        res = []
        tmp = root
        
        while tmp is not None or len(stack) > 0:
            
            while tmp is not None:
                stack.append(tmp)
                tmp = tmp.left
            node = stack.pop()
            res.append(node.val)
            tmp = node.right
            
        return res
        










`
