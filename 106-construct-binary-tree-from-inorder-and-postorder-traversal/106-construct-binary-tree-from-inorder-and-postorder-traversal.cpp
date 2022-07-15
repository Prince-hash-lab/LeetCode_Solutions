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
      TreeNode* bt(vector<int>& postorder, vector<int>& inorder, int &preind, int is, int ie)
    {
        if(is>ie) return NULL;
        TreeNode* root=new TreeNode(postorder[preind--]);
        int ind;
        for(int i=is; i<=ie; i++)
        {
            if(inorder[i]==root->val) 
            {
                ind=i;
                break;
            }
        }
        root->right=bt(postorder, inorder, preind,ind+1, ie);
        root->left=bt(postorder, inorder, preind, is, ind-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int  n=postorder.size(),preind=n-1;
        return bt(postorder, inorder, preind, 0, n-1);
    }
};