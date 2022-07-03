class Solution {
public:
    void subsets(vector<int> nums, int n, vector<int> v1, set<vector<int>> &st)
    {
        if(n==0) 
        { sort(v1.begin(), v1.end()); st.insert(v1); return ;}
        subsets(nums, n-1, v1, st);
        v1.push_back(nums[n-1]);
        subsets(nums, n-1, v1, st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size();
        set<vector<int>> st;
        subsets(nums, n, temp, st);
        
        for(auto x : st)
        {
            ans.push_back(x);
        }
        return ans;
    }
};