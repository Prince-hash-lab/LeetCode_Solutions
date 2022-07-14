class Solution {
public:
    // int lcs(string t1, string t2, int i, int j)
    // {
    //     if(i==-1 or j==-1) return 0;
    //     if(t1[i]==t2[j]) return 1+lcs(t1, t2, i-1, j-1);
    //     return max(lcs(t1,t2,i-1,j), lcs(t1,t2,i,j-1));
    // }
    
    int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.length(), n2=t2.length();
        // return lcs(text1, text2, n1-1, n2-1);
        int dp[n1+1][n2+1];
        for(int i=0; i<n1+1; i++)
            dp[i][0]=0;
        for(int i=0; i<n2+1; i++)
            dp[0][i]=0;
        for(int i=1; i<n1+1; i++)
        {
            for(int j=1; j<n2+1; j++)
            {
                if(t1[i-1]==t2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    
        return dp[n1][n2];
    }
};