/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int rt=root->val, pval=p->val, qval=q->val;
        if(root->val==pval or root->val==qval) return root;
        if(rt>min(pval,qval) and rt<max(pval,qval)) return root;
        if(rt<min(pval, qval)) return lowestCommonAncestor(root->right, p, q);
        return lowestCommonAncestor(root->left, p, q);
        
    }
};