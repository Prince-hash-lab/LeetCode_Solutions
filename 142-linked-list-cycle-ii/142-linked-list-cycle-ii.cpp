/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
          if(head==NULL or head->next==NULL) return NULL;
        if(head->next==head) return head;
        ListNode* slow=head, *fast=head;
        do
        {
            slow=slow->next;
            fast=fast->next->next;
            
        }while(slow!=NULL and fast!=NULL and fast->next!=NULL and slow!=fast);
       if(slow==NULL or fast==NULL or fast->next==NULL) return NULL;
        
        fast=head;
        if(slow==fast) return slow;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow->next;
    }
};