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
    void inor(TreeNode* root, vector<int> &ino)
    {
        if(root==NULL) return ;
        inor(root->left, ino);
        ino.push_back(root->val);
        inor(root->right, ino);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        vector<int> ino;
        inor(root, ino);
        int low=0, high=ino.size()-1, val;
        while(low<high)
        {
            val=ino[low]+ino[high];
            if(val==k) return true;
            else if(val<k) low++;
            else high--;
        }
        return false;
    }
};