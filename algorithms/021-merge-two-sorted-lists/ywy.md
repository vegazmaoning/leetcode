利用 哑节点，并依次比较2个链表中的头节点中的值
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dumb1 = dumb2 = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                dumb1.next = l1
                dumb1 = dumb1.next
                l1 = l1.next
            else:
                dumb1.next = l2
                dumb1 = dumb1.next
                l2 = l2.next
        if l1:
            dumb1.next = l1
        if l2:
            dumb1.next = l2
        return dumb2.next
            
            
        
        
        
```
