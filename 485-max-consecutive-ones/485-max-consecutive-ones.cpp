class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxval=0;
        int start=-1;
        int end=-1, sz=nums.size();
        for(int i=0; i<sz; i++)
        {
            if(nums[i]==0 and start!=-1) 
            {
                
                maxval=max(maxval, end-start+1);
                start=-1;
                end=-1;
            }
            else if(nums[i]==1 and start==-1)
            {
                start=i;
                end=i;
            }
            else if (nums[i]==1) end++;
        }
        if(end!=-1) maxval=max(maxval, end-start+1);
return maxval;
    }
};