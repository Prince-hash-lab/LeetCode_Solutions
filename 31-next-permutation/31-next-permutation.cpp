class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz=nums.size(), ind=sz-1, ind2=sz-1;
        for(int i=sz-1; i>=0; i--)
        {
            if(i==0) {ind=-1 ; break; }
            if(nums[i]>nums[i-1])
            {
                ind=i-1;
                break;
            }
        }
        for(int i=sz-1; i>=0 and ind!=-1; i--)
        {
            if(nums[i]>nums[ind])
            {
                ind2=i;
                break;
            }
        }
        if(ind!=-1)
            swap(nums[ind], nums[ind2]);
        int low=ind+1, high=sz-1;
        while(low<high)
        {
            swap(nums[low++], nums[high--]);
            
        }
    }
};