基本的思路是，对每个子链表的首节点找 min ，然后将该min node 链到哑节点上， 对于每一个节点重复上述动作。
时间复杂度 O(KN),其中 k 为子链数， N为总节点数。 通过 k 会比 N 少。 但是最坏情况是 k = N,导致时间复杂度为 O(N^2)。
于是会超时。 空间复杂度为 O(1)
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """ 
        n = len(lists)
        if n < 1:
            return None
        
        def get_min_in_lists(lists):
            min_val = None
            min_index = None
            min_node = None
            for i in range(n):
                if lists[i] is not None:
                    if min_val is None or (min_val is not None and lists[i].val < min_val):
                        min_val = lists[i].val
                        min_node = lists[i]
                        min_index = i
            if min_val is None:
                # lists are empty
                return None
            lists[min_index] = lists[min_index].next
            return min_node
                            
        dumb_node1 = dumb_node2 = ListNode(0)
        while True:
            new_node = get_min_in_lists(lists)
            if new_node is None:
                return dumb_node1.next

            dumb_node2.next = new_node
            dumb_node2 = dumb_node2.next
                
```
鉴于对所有首节点取 min 值占据了绝大部分的时间复杂度，通过采用 PriorityQueue，可以将时间复杂度降到 O(NlgK),
本质上是通过 堆 这样的数据结构来记录之前的 information。
空间复杂度为 O（K）
其中， PriorityQueue 是通过完全二叉树来做的结构，对于数据的插入和删除都是比较好的 lgK 的时间复杂度

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from Queue import PriorityQueue
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """ 
        dumb_node1 = dumb_node2 = ListNode(0)
        q = PriorityQueue(len(lists))
        for node in lists:
            if node:
                q.put((node.val, node))
        while not q.empty():
            min_node_val, min_node = q.get()
            dumb_node2.next = min_node
            dumb_node2 = dumb_node2.next
            if min_node.next is not None:
                q.put((min_node.next.val, min_node.next))
        return dumb_node1.next
```

最后看到还有一个更为简洁的方法，就是将所有的数据导入到列表中做 order，再做成链表
时间复杂度， O(NlgN),空间复杂度稳定在 O(N).和上面的来比，当 N 远比 K 大的时候，
也就是说每个子链表中的数据比较多，用PriorityQueue在时间和空间上都占有优势

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        all_node = []
        for l in lists:
            while l is not None:
                all_node.append(l)
                l = l.next
        all_node = sorted(all_node, key=lambda x: x.val)
        head = point = ListNode(-1)
        for i in all_node:
            point.next = i
            point = point.next
        return head.next
            
                
```
