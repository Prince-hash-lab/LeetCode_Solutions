class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz=nums.size();
        for(int i=1; i<sz; i++)
        {
            nums[i]+=nums[i-1];
        }
        int maxval=nums[0];
        int mini=nums[0];
        for(int i=1; i<sz; i++)
        {
            maxval=max(nums[i], max(maxval, nums[i]-mini));
            mini=min(mini, nums[i]);
        }
        return maxval;
            
    }
};