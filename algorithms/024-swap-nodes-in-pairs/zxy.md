```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        p = dummy
        h = head
        while h:
            if h and h.next:
                tmp = h.next
                p.next = tmp
                h.next = h.next.next
                tmp.next = h
                h = h.next
                p = p.next.next
            else:
                p.next = h
                h = h.next
        return dummy.next

        
```
