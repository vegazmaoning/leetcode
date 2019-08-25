/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head){
        return NULL;
    }
    struct ListNode* tmp = head;
    while(tmp->next){
        if(tmp->val == tmp->next->val){
            struct ListNode* tmpNode = tmp->next;
            tmp->next = tmp->next->next;
            free(tmpNode);
            tmpNode = NULL;
        }else{
            tmp = tmp->next;
        }
    }
    return head;
}


