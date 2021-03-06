class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int res=0, n=cost.size();
        for(int i=n-3; i>=0; i--)
            cost[i]=cost[i]+min(cost[i+1], cost[i+2]);
        return min(cost[0], cost[1]);
    }
};
const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();