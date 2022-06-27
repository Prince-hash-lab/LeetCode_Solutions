class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int len=nums.size(), curr1=INT_MIN, curr2=INT_MIN, c1=0, c2=0, i;
        for(i=0; i<len; i++)
        {
            if(nums[i]==curr1)
            {
                c1++;
            }
            else if(nums[i]==curr2)
            {
                c2++;
            }
            else if(c1==0)
            {
                curr1=nums[i];
                c1++;
            }
            else if(c2==0)
            {
               curr2=nums[i];
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1=0; c2=0;
        for(int i=0; i<len; i++)
        {
            if(curr1!=INT_MIN and nums[i]==curr1) c1++;
            if(curr2!=INT_MIN and nums[i]==curr2) c2++;
        }
        if(c1>(len/3)) ans.push_back(curr1);
        if(c2>(len/3)) ans.push_back(curr2);
        
        return ans;
    }
};