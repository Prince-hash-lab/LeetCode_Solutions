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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* curr1=list1,* curr2=list2;
        if(curr1!=NULL and curr2!=NULL and curr1->val>curr2->val) 
        {
            swap(curr1, curr2);
        }
        ListNode* head=curr1,* tail=curr1;
        if(curr1!=NULL) curr1=curr1->next;
        
        while(curr1!=NULL and curr2!=NULL)
        {
            if(curr1->val>curr2->val)
            {
                swap(curr1, curr2);
            }
            else
            {
                tail->next=curr1;
                tail=tail->next;
                curr1=curr1->next;
            }
        }
        if(curr1==NULL and tail!=NULL) tail->next=curr2;
        if(curr2==NULL and tail!=NULL) tail->next=curr1;
        return head;
    }
};