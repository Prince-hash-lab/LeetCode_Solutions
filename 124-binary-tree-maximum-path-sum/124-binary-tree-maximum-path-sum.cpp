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
    int maxsum(TreeNode* root, int &ans)
    {
       if(root==NULL) return 0;
        
        int lh=maxsum(root->left, ans);
        int rh=maxsum(root->right, ans);
        ans=max(ans, root->val+lh+rh);
        ans=max(root->val, ans);
        ans=max(ans, root->val+lh);
        ans=max(ans, root->val+rh);
        return max(root->val, max(root->val+lh, root->val+rh));
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=root->val;
        maxsum(root, ans);
        return ans;
    }
};