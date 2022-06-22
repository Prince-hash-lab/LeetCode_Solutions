class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr=1, val=nums[0]; 
        int sz=nums.size();
        for(int i=1 ; i<sz; i++)
        {
            if(nums[i]==val) curr++;
            else if(nums[i]!=val and curr!=1) curr--;
            else
            {
                val=nums[i];
            }
        }
        return val;
    }
};