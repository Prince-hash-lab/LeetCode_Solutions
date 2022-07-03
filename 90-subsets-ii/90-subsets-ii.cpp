class Solution {
public:
    void subsets(vector<int> nums,int i,  int n, vector<int> v1, vector<vector<int>> &ans)
    {
       
       ans.push_back(v1);
       // v1.push_back(nums[i]);
        for(int ind=i; ind<n; ind++)
        {
            if(i!=ind and nums[ind]==nums[ind-1]) continue;
            v1.push_back(nums[ind]);
            subsets(nums, ind+1, n, v1, ans);
            v1.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size(), i=0;
        sort(nums.begin(), nums.end());
        subsets(nums,i, n, temp, ans);
       
        return ans;
    }
};