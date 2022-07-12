class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, h=nums.size()-1;
        while(l<h)
        {
            
            int m=(l+h)>>1;
            // cout<<l<<" "<<h<<" "<<m<<endl;
            if(m!=0 and m!=nums.size()-1 and nums[m]!=nums[m+1] and nums[m]!=nums[m-1])
            {
                return nums[m];
            }
            if(m%2==0)
            {
                if(nums[m]!=nums[m+1]) h=m-1;
                else l=m+1;
            }
            else 
            {
                if(nums[m]!=nums[m-1]) h=m-1;
                else l=m+1;
            }
        }
        return nums[l];
    }
};
const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();