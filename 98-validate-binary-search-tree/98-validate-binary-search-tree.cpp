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
    void inorder(TreeNode* root, bool &ans,bool &first , int &prev)
    {
        if(root==NULL) return ;
        inorder(root->left, ans,first,  prev);
        
        if(!first and prev>=root->val) 
        {
            ans=false;
            return ;
        }
        prev=root->val;
        first=false;
        inorder(root->right, ans,first, prev);
    }
    bool isValidBST(TreeNode* root) {
        bool ans=true, first=true;
        int prev=NULL;
        
        inorder(root, ans,first ,  prev);
        return ans;
        
    }
};