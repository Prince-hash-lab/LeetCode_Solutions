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
    bool isy(TreeNode* lf, TreeNode* rt)
    {
        if(lf==NULL or rt==NULL)
        {
            if(lf==rt) return true;
            return false;
        }
        if(lf->val!=rt->val) return false;
        return isy(lf->right, rt->left) and isy(lf->left, rt->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return false;
        return isy(root->left, root->right);
    }
};