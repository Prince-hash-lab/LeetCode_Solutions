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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr1=head, *curr2=head ;
        if(head==NULL) 
            return NULL;
        while(n--!=0)
             curr1=curr1->next;
    
        if(!curr1) 
            return curr2->next;
        
        while(curr1->next!=NULL)
        {
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        if(curr2->next==NULL) 
            return NULL;
        curr2->next=curr2->next->next;
        return head;
    }
};