```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        p = head
        flag = 0
        while l1 and l2:
            
            val = l1.val + l2.val + flag
            if val >= 10:
                val -= 10
                flag = 1
            else:
                flag = 0
            tmp = ListNode(val)
            p.next = tmp
            p = p.next
            l1 = l1.next
            l2 = l2.next
        lr = l1 if l1 else l2
        while lr:
            val = lr.val + flag
            if val >= 10:
                val -= 10
                flag = 1
            else:
                flag = 0
            tmp = ListNode(val)
            p.next = tmp
            p = p.next
            lr = lr.next
        if flag:
            tmp = ListNode(flag)
            p.next = tmp
        return head.next
                
```
