class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n=nums.size(), val1, val2, low, high;
        for(int  i=0; i<n-2; i++)
        {
            if(i==0 or nums[i]!=nums[i-1])
            {
            val1=nums[i];
            low=i+1;  high=n-1;
            while(low<high)
            {
                val2=nums[low]+nums[high]+nums[i];
                if(val2==0)
                {
                    ans.push_back({nums[i], nums[low], nums[high]}); 
                    // do{low++;}
                    while(low<high and nums[low]==nums[low+1]) low++; 
                    // if(nums[low]==nums[low-1]) low++;
                    // do{high--;}
                    while(low<high and nums[high]==nums[high-1]) high--;
                    // if(nums[high]==nums[high+1]) high++;
                    low++;
                     high--;
                    
                }
                else if(val2>0) high--;
                else if(val2<0) low++;
            }
            }
            // while(nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};