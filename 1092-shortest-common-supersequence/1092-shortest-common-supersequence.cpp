class Solution {
public:
    int fn(string s1, string s2, int m, int n)
    {
        if(m==0 ) return n;
        if(n==0) return m;
        if(s1[m-1]==s2[n-1])
            return 1+fn(s1, s2, m-1, n-1);
        else
            return 1+min(fn(s1, s2, m-1, n), fn(s1, s2, m, n-1));
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int m=s1.length(), n=s2.length();
        // cout<<fn(s1, s2, m, n)<<" ";
        vector<vector<int>> dp(m+1, vector<int> (n+1));
        for(int i=0 ;i<m+1; i++)  dp[i][0]=i;
        for(int i=0 ;i<n+1; i++)  dp[0][i]=i;
        
        for(int i=1 ;i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=1+ min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i=m, j=n;
        string ans="";
        while(i>0 and j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                ans+=s1[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    ans+=s2[j-1];
                    j--;
                }
                else
                {
                    ans+=s1[i-1];
                    i--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        // cout<<ans<<endl;
        if(i==0) ans=s2.substr(0, j)+ans;
        else ans=s1.substr(0, i)+ans;
        
        // cout<<ans<<" i="<< i<<" j="<<j<<endl;
        
        return ans;
    }
    
    
    
    
    
    
};