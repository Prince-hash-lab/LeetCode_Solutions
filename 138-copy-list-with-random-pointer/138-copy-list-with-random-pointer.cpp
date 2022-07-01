/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head,* curr1,* curr3;
        if(head==NULL) return head;
        while(curr!=NULL)
        {
            curr1=curr->next;
            curr3=new Node(curr->val);
            curr3->next=curr1;
            curr->next=curr3;
            curr=curr->next->next;
        }
        curr=head;
        while(curr!=NULL)
        {
            if(curr->random!=NULL)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        curr1=head->next;
        curr3=curr1;
        curr=head;
        while(curr!=NULL)
        {
            curr->next=curr->next->next;
            if(curr3->next!=NULL)
                curr3->next=curr3->next->next;
            curr=curr->next;
            curr3=curr3->next;
        }
        return curr1;
    }
};