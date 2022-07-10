class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int res=0, n=cost.size();
        vector<int> dp(n,0);
        dp[n-1]=cost[n-1];
        dp[n-2]=cost[n-2];
        for(int i=n-3; i>=0; i--)
            dp[i]=cost[i]+min(dp[i+1], dp[i+2]);
        return min(dp[0], dp[1]);
    }
};