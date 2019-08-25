/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 遍历链表，获取到链表的节点个数，和 k 值做比较，进行取余， 实际操作数为：k % n
// 第二次遍历链表，直至最后只剩下 k % n 个节点时，进行旋转即可.
// 复杂度 为 O(n)

struct ListNode* rotateRight(struct ListNode* head, int k){
    // critical condition
    if(!head){
        return NULL;
    }
    if (k == 0){
        return head;
    }
    
    // tmp1 & tmp2 for iteration
    struct ListNode* tmp1, *tmp2;
    tmp1 = tmp2 = head;
    // end if the list tail
    struct ListNode *end;
    
    // count1 for length of List
    // count2 for find the rotation start node
    int count1, count2;
    count1 = count2 = 0;
    while(tmp1){
        count1 += 1;
        end = tmp1;
        tmp1 = tmp1->next;
        
    }
    k = count1 - (k % count1);
    if( k == 0 || k == count1 ){
        return head;
    }
    struct ListNode* newHead = NULL;
    while(tmp2){
        count2 += 1;
        if(count2 == k){
            newHead = tmp2->next;
            end->next = head;
            tmp2->next = NULL;
            return newHead;
        }else{
            tmp2 = tmp2->next;    
        }
    }
    return newHead;
}
