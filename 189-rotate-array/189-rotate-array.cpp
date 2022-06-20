class Solution {
public:
    void rotate(vector<int>& nums, int k) {
           
//         # reverse an array from n-k to n-1
//         # reverse an array from 0 to n-k-1
//         # reverse the whole array 
        
//         #approach 2
//         # shift each element by k in a cycle 
//         # till we are at the same position
        
        int temp;
        int n=nums.size();
        k=k%n;
        int gcd=__gcd(n, k);
        for(int i=0; i<gcd; i++)
        {
            int ind=i;
            int ind2=(ind+k)%n;
            int temp=nums[ind];
            while(ind2!=ind)
            {
                swap(temp, nums[ind2]);
                ind2=(ind2+k)%n;
            }
            swap(temp, nums[ind2]);
        }
        
        
    }
};