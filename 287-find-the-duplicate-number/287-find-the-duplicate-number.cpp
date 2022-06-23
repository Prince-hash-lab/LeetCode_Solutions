class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sz=nums.size(), sum=0;
       sort(nums.begin(), nums.end());
        for(int i=1; i<sz; i++)
        {
            if(nums[i]==nums[i-1]) return nums[i];
        }
        return -1;
    }
};