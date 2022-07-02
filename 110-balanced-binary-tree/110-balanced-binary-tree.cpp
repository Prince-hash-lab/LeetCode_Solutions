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
    int height(TreeNode* root, bool &ans)
    {
        if(root==NULL) return 0;
        int lh=height(root->left, ans);
        int rh=height(root->right, ans);
        if(lh!=rh and lh!=rh+1 and rh!=lh+1) ans=false;
        return max(1+lh, 1+rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        bool ans=true;
        height(root, ans);
        return ans;
    }
};