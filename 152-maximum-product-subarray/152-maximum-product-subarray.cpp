class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int res=nums[0], prod=1, n=nums.size();
        bool iszero=false;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
            {  res=max(res, nums[i]);
                prod=1;
            iszero=true;}
            else
            {
                prod*=nums[i];
                res=max(res, prod);
            }
        }
        prod=1;
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i]==0)
            {   res=max(res, nums[i]);
                prod=1;
                iszero=true;
            }
            else
            {
                prod*=nums[i];
                res=max(res, prod);
            }
        }
        if(iszero) res=max(res, 0);
        return res;
        
    }
};
const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();