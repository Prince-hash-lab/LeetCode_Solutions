class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zr=0, sz=nums.size(), tw=sz-1;
        for(int i=0; i<=tw; i++)
        {
            if(nums[i]==2)
            {
                swap(nums[i], nums[tw--]);
                    i--;
            
            }
            else if(nums[i]==0)
            {
                swap(nums[i], nums[zr++]);
                
            }
            
        }
      
    }
};