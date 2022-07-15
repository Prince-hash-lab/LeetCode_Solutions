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
    TreeNode* bt(vector<int>& preorder, vector<int>& inorder, int &preind, int is, int ie)
    {
        if(is>ie) return NULL;
        TreeNode* root=new TreeNode(preorder[preind++]);
        int ind;
        for(int i=is; i<=ie; i++)
        {
            if(inorder[i]==root->val) 
            {
                ind=i;
                break;
            }
        }
        root->left=bt(preorder, inorder, preind, is, ind-1);
        root->right=bt(preorder, inorder, preind,ind+1, ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preind=0, n=preorder.size();
        return bt(preorder, inorder, preind, 0, n-1);
    }
};