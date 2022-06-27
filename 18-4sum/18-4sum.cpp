class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        long long n=nums.size(), sum, val1, val2;
        for(long long i=0; i<n; i++)
        {
            for(long long j=i+1; j<n; j++)
            {
                sum=target-nums[i]-nums[j];
                long long low=j+1, high=n-1;
                while(low<high)
                {
                    if(nums[low]+nums[high]==sum)
                    {
                        val1=nums[low];  val2=nums[high];
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while(low<high and nums[low]==val1) low++;
                        while(low<high and nums[high]==val2) high--;
                    }
                    else if(nums[low]+nums[high]<sum) low++;
                    else high--;
                }
                while(j+1<n and nums[j]==nums[j+1]) j++;
            }
            while(i+1<n and nums[i]==nums[i+1]) i++;
        }
        return ans ;
    }
};