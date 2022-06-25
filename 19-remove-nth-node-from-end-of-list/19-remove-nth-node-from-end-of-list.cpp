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
        if(head==NULL) return NULL;
        while(n--!=0)
        {
            curr1=curr1->next;
        }
        if(curr1==NULL) 
        {
            head=curr2->next;
            delete(curr2);
            return head;
        }
        while(curr1!=NULL and curr1->next!=NULL)
        {
            curr1=curr1->next;
            curr2=curr2->next;
        }
        if(curr2->next==NULL) 
        {   delete(curr2);
            return NULL;
        }
       
        
        curr1=curr2->next;
        curr2->next=curr2->next->next;
        delete(curr1);
        return head;
    }
};