/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> qu;
        qu.push(root);
        qu.push(NULL);
        Node* temp;
        int sz=0;
        while(!qu.empty())
        {   sz=qu.size();
            for(int i=0; i<sz; i++)
            {
                temp=qu.front();
                qu.pop();
                if(temp!=NULL)
                {
                    temp->next=qu.front();
                    if(temp->left)qu.push(temp->left);
                    if(temp->right)qu.push(temp->right);
                    
                }
            
            }
         if(qu.empty()) break;
         qu.push(NULL);
        }
        return root;
        
    }
};