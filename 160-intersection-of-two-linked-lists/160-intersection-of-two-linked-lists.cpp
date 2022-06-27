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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     ListNode* curr1=headA, *curr2=headB;
        while(curr1!=NULL and curr2!=NULL)
        {
            curr1=curr1->next;
            curr2=curr2->next;
        }
        int val=0;
        if(curr1==NULL) {curr1=headB; val=1;}
        else if(curr2==NULL) curr2=headA;
        while(curr1!=NULL and curr2!=NULL )
        {
            curr1=curr1->next;
            curr2=curr2->next;
        }
        if(val==0) curr1=headB;
        else curr2=headA;
        while(curr1!=curr2) 
        {
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return curr1;
    }
};