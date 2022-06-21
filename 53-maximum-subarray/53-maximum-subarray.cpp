class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz=nums.size();
        int maxval=nums[0];
        int res=nums[0];
        for(int i=1; i<sz; i++)
        {
            maxval=max(nums[i], maxval+nums[i]);
            res=max(maxval, res);
        }
        
     
        return res;
            
    }
};