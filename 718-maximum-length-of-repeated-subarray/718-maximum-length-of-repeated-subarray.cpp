class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        int n=n1.size(), m=n2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        for(int i=0; i<n+1; i++) dp[i][0]=0;
        for(int i=0; i<m+1; i++) dp[0][i]=0;
        int res=0;
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(n1[i-1]==n2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                 res=max(res, dp[i][j]);   
                }
                else
                    dp[i][j]=0;
            }
        }
        return res;
    }
};