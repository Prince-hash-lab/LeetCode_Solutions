class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dqu;
        int n=nums.size();
        dqu.push_back(0);
        for(int i=0; i<n; i++)
        {
            while(!dqu.empty() and nums[dqu.back()]<=nums[i]) dqu.pop_back();
            dqu.push_back(i);
            if(dqu.front()==i-k) dqu.pop_front();
            if(i>=k-1) ans.push_back(nums[dqu.front()]); 
            
        }
        return ans;
    }
};
const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();