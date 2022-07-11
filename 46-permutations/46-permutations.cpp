class Solution {
public:
    void fperm(vector<int>& nums, int n,vector<vector<int>> &ans, unordered_map<int,int > &mp, vector<int>& v1)
    {
        if(v1.size()==n) 
        {
            ans.push_back(v1);
            return ;
        }
        // for(auto x: v1) cout<<x<<" ";
        // cout<<endl;
        for(int j=0; j<n; j++)
        {
            if(!mp.count(nums[j]))
            {
                // cout<<" inside "<<endl;
                mp[nums[j]]=1;
                v1.push_back(nums[j]);
                fperm(nums, n, ans, mp, v1);
                v1.pop_back();
                mp.erase(nums[j]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int > mp;
        vector<int> v1;
        int n=nums.size();
        fperm(nums, n, ans, mp, v1);
        // sort(ans.begin(), ans.end());
        return ans;
    }
};