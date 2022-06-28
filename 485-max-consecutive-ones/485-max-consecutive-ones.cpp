class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size=nums.size(), curr=0, res=0;
        if(nums[0]==1) {curr=1; res=1;}
        for(int i=1 ;i<size; i++)
        {
            if(nums[i]==0) { curr=0; continue;}
            curr++;
            res=max(curr, res);
            }
        return res;
    }
};