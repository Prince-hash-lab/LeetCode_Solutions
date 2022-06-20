class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        int k=0;
        for(int i=0; i<size-1; i++)
        {
            if(nums[i]!=nums[i+1])
                nums[k++]=nums[i];
        }
        nums[k++]=nums[size-1];
        return k;
    }
};