/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
//     ListNode* reverse(ListNode* head)
//     {
//         if(head==NULL) return NULL;
        
//     }
    
    bool isPalindrome(ListNode* head) {
        ListNode * slow=head, *fast=head,* curr1, *curr2;
        if(head->next==NULL) return true;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow!=NULL and slow->next!=NULL)
        {
             curr1=slow->next;
             curr2=curr1->next;
             slow->next=NULL;
             while(curr1!=NULL)
            {

                curr1->next=slow;
                slow=curr1;
                curr1=curr2;
                if(curr1!=NULL)
                    curr2=curr1->next;
            }
        }
        fast=head;
        while(fast!=NULL and slow!=NULL)
        {
            if(slow->val!=fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
       return true;
        
    }
};