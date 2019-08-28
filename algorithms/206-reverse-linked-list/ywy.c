/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = head->next;
    while(cur && next){
        cur->next = prev;
        prev = cur;
        cur = next;
        next = cur->next;
    }
    cur->next = prev;
    return cur;
    
    
    
}



