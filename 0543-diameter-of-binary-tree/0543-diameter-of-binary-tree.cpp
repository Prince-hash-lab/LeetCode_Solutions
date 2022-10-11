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
    int dbt(TreeNode* root, int &res)
    {
        if(root==NULL) return 0;
        int lh=dbt(root->left, res);
        int rh=dbt(root->right, res);
        res=max(res, 1+lh+rh);
        return 1+max(lh, rh);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
      int res=0;
      dbt(root , res);
         return res-1;
    }
};