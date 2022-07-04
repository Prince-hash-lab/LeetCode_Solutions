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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> qu;
        // stack<
        int sz, flag=0, ind;
        TreeNode* temp;
        qu.push(root);
        while(!qu.empty())
        {
            sz=qu.size();
            vector<int> v1(sz);
            for(int i=0; i<sz; i++)
            {
                temp=qu.front();
                if(flag==0) ind=i;
                else ind=sz-i-1;
                v1[ind]=temp->val;
                qu.pop();
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
                
            }
            ans.push_back(v1);
            flag=!flag;
        }
        return ans;
    }
};