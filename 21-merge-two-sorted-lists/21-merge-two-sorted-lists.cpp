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
        if(list2==NULL) return list1 ;
        if(list1->val>list2->val) swap(list1, list2);
        ListNode* curr1=list1,* curr2=list2, *curr3;
        while(curr1->next!=NULL and curr2!=NULL)
        {
            if(curr1->next->val>curr2->val)
            {
                curr3=curr1->next;
                curr1->next=curr2;
                curr1=curr2;
                curr2=curr3;
            }
            else curr1=curr1->next;
        }
        if(curr1->next==NULL) curr1->next=curr2;
        
        return list1;
    }
};