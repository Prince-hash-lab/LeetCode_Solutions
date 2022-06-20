class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0, maxval=0;
        for (auto i = nums.begin(); i != nums.end(); ++i)
        {
            if(*i==1) 
            { res++;
             maxval=max(maxval, res);
            }
            else
               res=0;
            
        }
        
return maxval;
    }
};