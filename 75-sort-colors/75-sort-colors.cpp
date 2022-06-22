class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zr=0, on=0, tw=0, sz=nums.size();
        for(int i=0; i<sz; i++)
        {
            if(nums[i]==0) zr++;
            else if(nums[i]==1) on++;
            else tw++;
        }
        int curr=0;
        while(zr--) nums[curr++]=0;
        while(on--) nums[curr++]=1;
        while(tw--)  nums[curr++]=2;
    }
};