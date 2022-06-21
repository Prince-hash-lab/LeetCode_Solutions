/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> iot;
        stack<TreeNode*> temp;
        TreeNode* curr=root;
        temp.push(curr);
        while(curr!=NULL and !temp.empty())
        {
            curr=temp.top();
            if(curr->left==NULL) 
            {
                iot.push_back(curr->val);
                temp.pop();
            }
            
            if(curr->left!=NULL)
            {
                temp.push(curr->left);
                curr->left=NULL;
            }
            else if(curr->right!=NULL)
            {
                temp.push(curr->right);
            }
            
        }
        return iot;
    }
};