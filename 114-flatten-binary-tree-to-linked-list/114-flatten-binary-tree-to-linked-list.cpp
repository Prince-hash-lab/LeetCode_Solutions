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
    TreeNode* ft(TreeNode* root,TreeNode*  &prevptr)
    {
        if(root==NULL) return NULL;
        TreeNode* lf=root->left;
        TreeNode* rt=root->right;
        prevptr=root;
        // cout<<prevptr->val<<" ";
        if(lf==NULL and rt==NULL) return root;
        root->left=NULL;
        TreeNode* t1=prevptr;
        if(lf!=NULL)
            t1->right=ft(lf, prevptr);
        
        // cout<<prevptr->val<<" ";
        TreeNode* t2=prevptr;
        if(rt!=NULL)
            t2->right=ft(rt, prevptr);
        return root;
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return ;
        
        TreeNode*  prevptr=NULL;
        ft(root, prevptr);
        
    }
};