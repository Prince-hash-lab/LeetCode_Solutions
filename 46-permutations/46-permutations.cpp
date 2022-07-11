class Solution {
public:
    void fperm(vector<int>& nums, int i, int n,vector<vector<int>> &ans )
    {
        if(i==n-1){ans.push_back(nums); return;} 
        for(int j=i; j<n; j++)
        {

            swap(nums[j], nums[i]);
            fperm(nums, i+1,n, ans );
            swap(nums[j], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        fperm(nums, 0, n, ans);
        return ans;
    }
};