```
先找到链表的长度  例如要删除倒数第2个  即n=2  加入链表长度为5 ，则找到第2(length-n)个元素，使他的next等于next.next
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
        length = 1
        tmp_link = head
        while tmp_link.next:
            length += 1
            tmp_link = tmp_link.next
        if length == n:
            return head.next
        tmp = 1
        a = head
        while length - tmp > n:
            a = a.next
            tmp += 1
        a.next = a.next.next
        return head
        
```
