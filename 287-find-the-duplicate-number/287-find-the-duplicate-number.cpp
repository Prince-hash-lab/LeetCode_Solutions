class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sz=nums.size(), val=-1;
      
        for(int i=0; i<sz; i++)
        {
            if(nums[abs(nums[i])-1]<0) return abs(nums[i]);
            nums[abs(nums[i])-1]*=-1;
        }
        return -1;
    }
};