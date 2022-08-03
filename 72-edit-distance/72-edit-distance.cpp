class Solution {
public:
    // int md(string w1, string w2, int m, int n)
    // {
    //     if(m==0) return n;
    //     if(n==0) return m ;
    //     if(w1[m-1]==w2[n-1]) return md(w1, w2, m-1, n-1);
    //     return 1+min({md(w1, w2, m-1, n), md(w1, w2, m, n-1), md(w1, w2, m-1, n-1)});
    // }
    int minDistance(string w1, string w2) {
        // return md(w1, w2, w1.length(), w2.length());
        int m=w1.length(), n=w2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=0; i<=m; i++) dp[i][0]=i;
        for(int i=0; i<=n; i++) dp[0][i]=i;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(w1[i-1]==w2[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
//          for(int i=0; i<=m; i++)
//         {
//             for(int j=0; j<=n; j++)
//             {
//                 cout<<dp[i][j]<<" ";
//             }
//              cout<<endl;
//          }
        
        return dp[m][n];
        
    }
};