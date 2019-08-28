/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    if(m == 1){    
        int pos = 1;
        struct ListNode* prev = dummy;
        struct ListNode* cur = head;
        struct ListNode* newTail = head;
        struct ListNode* after = cur->next;
        while(pos <= n){
            cur->next = prev;
            prev = cur;
            cur = after;
            if(cur){
                after = cur->next;
            }
            pos += 1;
        }
        newTail->next = cur;
        return prev;
    }else{
        int pos = 1;
        struct ListNode* newHead = dummy;
        while(pos < m){
            newHead = newHead->next;
            pos += 1;
        }
        struct ListNode* prev = newHead;
        struct ListNode* cur = newHead->next;
        struct ListNode* newTail = cur;
        struct ListNode* after = cur->next;
        while(pos <= n){
            cur->next = prev;
            prev = cur;
            cur = after;
            if(cur){
                after = cur->next;
            }
            pos += 1;
        }
        newHead->next = prev;
        newTail->next = cur;
        return dummy->next;
    }
    return head;
}


