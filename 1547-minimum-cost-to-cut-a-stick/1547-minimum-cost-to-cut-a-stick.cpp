

class Solution {
public:
    
    // int mc(vector<int> cuts, int low , int high, vector<vector<int>> &dp)
    // {
    //     // if(low+1==high or low==high) return 0;
    //     if(dp[low][high]!=-1) return dp[low][high];
    //     if(low>=high || low+1==high) return dp[low][high]==0;
    //     int res=INT_MAX;
    //     for(int i=low+1;i<high; i++)
    //     {   long cost=INT_MAX;
    //         cost=cuts[high]-cuts[low]+mc(cuts, low, i, dp)+mc(cuts, i , high, dp);
    //         res=min(int(cost), res);
    //     }
    //     return dp[low][high]=res;
    // }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        vector<vector<long>> dp(103, vector<long> (103, INT_MAX));
        sort(cuts.begin(), cuts.end());
        for(int i=0; i<cuts.size(); i++ )
        {
            // if(low+1<cuts.length()) 
            //     dp[low][low+1]=0;
            dp[i][i]=0;
        }
        for(int i=cuts.size()-2; i>=0; i--)
        {
            for(int j=i+1; j<cuts.size(); j++)
            {
                if(i+1==j)
                {
                    dp[i][j]=0;
                    continue;
                }
                for(int k=i+1; k<j; k++)
                {
                    dp[i][j]=min(dp[i][j], cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
                }
            }
        }
        return dp[0][cuts.size()-1];
    }
    
    
    
};