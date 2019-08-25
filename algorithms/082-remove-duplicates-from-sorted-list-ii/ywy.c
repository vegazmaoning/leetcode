/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 站在哑结点上来看，看后面两个节点的值是否相等，如果相等，删除掉第一个后面的值，再接着看后面两个是否相等
// 如果后面两个不相等，看刚才删除节点的值是否和下一个节点的值相等，如果相等，说明是“残余节点”，继续删除。
// 否则，直接看下一个节点。

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head){
        return NULL;
    }
    
    struct ListNode* dummy = malloc(sizeof(struct ListNode));

    dummy->next = head;
    struct ListNode* deleted = NULL;
    struct ListNode* tmp = dummy;
    
    int delVal = 0;
    int delFlag = 0;
    while(tmp->next && tmp->next->next){
        if(tmp->next->val == tmp->next->next->val){
            delVal = tmp->next->val;
            deleted = tmp->next;
            delFlag = 1;
            tmp->next =tmp->next->next;
            free(deleted);
        }else{
            if(delFlag == 1 && tmp->next->val == delVal){
                deleted = tmp->next;
                tmp->next = tmp->next->next;
                free(deleted);
            }else{
                tmp = tmp->next;
            }
        }
    }
    // 对于 while 循环退出条件进行边界测试
    if(tmp->next && tmp->next->val == delVal){
        deleted = tmp->next;
        tmp->next = NULL;
        free(deleted);
    }
    return dummy->next;
}


