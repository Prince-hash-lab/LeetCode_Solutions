class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0, maxval=0, sz=nums.size();
        for(int i=0; i<sz; i++)
        {
            if(nums[i]==1) 
            { res++;
             maxval=max(maxval, res);
            }
            else
               res=0;
            
        }
        
return maxval;
    }
};