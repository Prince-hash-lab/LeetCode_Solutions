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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<pair<TreeNode* , pair<int,int>>> qu;
        map<int,map<int,  vector<int>>> mp;
        pair<TreeNode* , pair<int, int>> temp;
        pair<int, int> temp1;
        TreeNode* n1;
        int n2, n3;
        vector<int> v1;
        qu.push({root, {0,0}});
        while(!qu.empty())
        {
            temp=qu.front();
            qu.pop();
            n1=temp.first;
            temp1=temp.second;
            if(!mp.count(temp1.second)) mp[temp1.second][temp1.first]={n1->val};
            else 
            {   
                v1=mp[temp1.second][temp1.first];
                v1.push_back(n1->val);
                mp[temp1.second][temp1.first]=v1;
                
            }
            if(n1->left) qu.push({n1->left, {temp1.first + 1, temp1.second - 1}});
            if(n1->right) qu.push({n1->right, {temp1.first + 1, temp1.second + 1}});
          
        }
        for(auto x : mp)
        {
            vector<int> vecna1;
            // cout<<" col: "<<x.first<<" ";
            for(auto y : x.second)
            {   
                vector<int> vecna2=y.second;
                sort(vecna2.begin(), vecna2.end());
                // cout<<" row : "<<y.first<<" ->";
                for(int val : vecna2)
                {  
                    // cout<<val<<" ";
                    vecna1.push_back(val);
                }
                
            }
            ans.push_back(vecna1);
            // cout<<endl;
        }
        return ans;
    }
};