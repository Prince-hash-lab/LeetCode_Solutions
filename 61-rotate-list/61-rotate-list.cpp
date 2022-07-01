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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr=head;
        if(head==NULL or head->next==NULL) return head;
        int ct=0;
        while(curr->next!=NULL)
        {
            curr=curr->next;  ct++;
        }
        ct++;
        curr->next=head;
        k=k%ct;
        ct=ct-k;
        curr=head;
        for(int i=0 ;i<ct-1; i++)
        {
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};