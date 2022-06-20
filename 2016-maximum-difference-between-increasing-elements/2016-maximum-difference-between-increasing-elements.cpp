class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int sz=nums.size(),maxval=nums[sz-1], maxdif=-1;
        for(int i=sz-2; i>=0; i--)
        {
            if(maxdif<(maxval-nums[i]) and maxval>nums[i] )
                 maxdif=maxval-nums[i];
              
            maxval=max(maxval, nums[i]);
        }
        return maxdif;
    }
};