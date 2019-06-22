同时循环两个链表   需要考虑的边界条件是  当链表没值  但是此时的和大于10的情况



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
        remainder = 0
        tmp = ListNode(0)
        result = tmp
        while l1 or l2 or remainder:
            if l1:
                tmp.val += l1.val
                l1 = l1.next
            if l2:
                tmp.val += l2.val
                l2 = l2.next
            remainder = tmp.val / 10
            tmp.val = tmp.val % 10
            if l1 or l2 or remainder:
                tmp.next = ListNode(remainder)
                tmp = tmp.next
        return result
