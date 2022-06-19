class Solution {
public:
int pivotIndex(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        // if(sum-nums[0]==0) return nums[0];
        int lfsum=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(lfsum==sum-nums[i]) return i;
            lfsum+=nums[i];
            sum-=nums[i];
        }
        return -1;
    }
};