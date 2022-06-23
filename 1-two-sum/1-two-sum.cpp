class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;
        vector<vector<int>> numi;
        int low=0, high=nums.size()-1;
        for(int i=0; i<=high; i++)
        {
            numi.push_back({nums[i],i});
        }
        sort(numi.begin(), numi.end());
        while(low<high)
        {
            if(numi[low][0]+numi[high][0]==target)
            {
                return {numi[low][1], numi[high][1]};
            }
            else if(numi[low][0]+numi[high][0]<target)
                low++;
            else high--;
        }
        return {};
    }
};