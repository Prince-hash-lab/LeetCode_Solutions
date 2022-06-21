class Solution {
public:
//     int bs(vector<int> &nums, int low, int high, int target)
//     {
        
//     }
    int search(vector<int>& nums, int target) {
        int sz=nums.size();
        int low=0, high=sz-1;
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                low=mid+1;
            else 
                high=mid-1;
                
        }
        return -1;
    }
};