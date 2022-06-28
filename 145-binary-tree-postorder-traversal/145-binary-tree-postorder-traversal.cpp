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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> mp;
        mp[NULL]=1;
        st.push(root);
        TreeNode* curr;
        while(!st.empty())
        {
            curr=st.top();
            if((curr->left==NULL and curr->right==NULL) or (mp.count(curr->left) and mp.count(curr->right)))
            {
                ans.push_back(curr->val);
                st.pop();
                continue;
            }
            if(curr->right!=NULL and !mp.count(curr->right))
            {
                st.push(curr->right);
                mp[curr->right]=1;
            }
            if(curr->left!=NULL and !mp.count(curr->left)) 
            { st.push(curr->left);
              mp[curr->left]=1;
            }
        }
        return ans;
        
    }
};