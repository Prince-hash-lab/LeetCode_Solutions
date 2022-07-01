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
     ListNode* reverseList(ListNode* head, ListNode* tail) {
        if(head==NULL or head->next==NULL) return head;
        ListNode* curr=NULL, * temp=head->next;
        while(temp!=tail)
        {
            head->next=curr;
            curr=head;
            head=temp;
            temp=temp->next;
        }
        head->next=curr;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* head1=head, *tail=head, *next1=head, *prevtail=NULL,*prevhead=NULL,  *curr;
        int val;
        while(head1!=NULL)
        {
            val=k;
            tail=head1;
            int i ;
            for(i=0 ;i<val-1 and tail!=NULL and tail->next!=NULL; i++)
            {
                tail=tail->next;
            }
            
            next1=tail->next;
            if(i==k-1)
            curr=reverseList(head1, tail->next);
            else curr=head1;
            if(prevtail==NULL) 
                   { head=curr; }
            else prevtail->next=curr;
            // tail1=head1;
            prevtail=head1;
            head1=next1;
        }
        return head;
    }
};