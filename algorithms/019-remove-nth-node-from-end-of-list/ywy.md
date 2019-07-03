set dumb node to simply the case when first node will be deleted

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # 2 个节点，间隔 n
        dumb = ListNode(0)
        dumb.next = head
        forward = afterward = dumb
        for i in range(n):
            forward = forward.next
            
        if forward.next is None:
            return head.next
        
        while forward.next is not None:
            forward = forward.next
            afterward = afterward.next

        afterward.next = afterward.next.next
        return head

```
