class Solution {
public:
    void rotate(vector<int>& nums, int k) {
           
//         # reverse an array from n-k to n-1
//         # reverse an array from 0 to n-k-1
//         # reverse the whole array 
        
//         #approach 2
//         # shift each element by k in a cycle 
//         # till we are at the same position
        
//         int temp;
//         int sz=nums.size();
//         for(int i=0; i<sz; i++)
//         {
            
//         }
        int n=nums.size();
        k=k%n;
        int low=n-k;
        int high=n-1;
        while(low<high)
        {
            swap(nums[low++], nums[high--]);
        }
        
        low=0;
        high=n-k-1;
        while(low<high)
        {
            swap(nums[low++], nums[high--]);
        }
        
        low=0;
        high=n-1;
        while(low<high)
        {
            swap(nums[low++], nums[high--]);
        }
        
        
    }
};