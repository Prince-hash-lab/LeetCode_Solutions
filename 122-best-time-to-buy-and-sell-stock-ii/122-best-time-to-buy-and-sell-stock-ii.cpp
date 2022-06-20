class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        int profit=0;
        for(int i=1;i<sz; i++)
        {
            // cout<<i<<" "<<prices[i]<<" "<<profit<<endl;
            if(prices[i]>prices[i-1])
                profit+=(prices[i]-prices[i-1]);
        }
        return profit;
    }
};