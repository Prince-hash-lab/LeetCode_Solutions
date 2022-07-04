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
   // if(root==NULL) return 0;
   //      queue<TreeNode*> qu;
   //      qu.push(root);
   //      int res=1, val=0;
   //      while(!qu.empty())
   //      {
   //          TreeNode* temp=
   //      }
    int widthOfBinaryTree(TreeNode* root) {
       if(root==NULL) return 0;
        queue<pair<TreeNode*, long long>> qu1;
        long long  res=1, currid, lmost, rmost, currmin, val;
        TreeNode* temp;
        qu1.push({root, 0});
        while(!qu1.empty())
        {
            long long  sz=qu1.size();
            currmin=qu1.front().second;
            for(long long i=0; i<sz; i++)
            {
                temp=qu1.front().first;
                val=qu1.front().second;
                currid=val-currmin;
                if(i==0) lmost=currid;
                if(i==sz-1) rmost=currid;
                if(temp->left) qu1.push({temp->left, (currid * 2) +1 });
                if(temp->right) qu1.push({temp->right, (currid * 2) +2 });
                qu1.pop();
            }
            res=max(res, rmost-lmost+1);
        }
        return res;
        
    }
};