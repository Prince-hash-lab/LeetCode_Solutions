class Solution {
public:
    
    bool wordBreak(string str, vector<string>& B) {
         //code here
        unordered_set<string> st;
        int n=str.size();
        vector<vector<bool>> memo(n+1, vector<bool> (n+1, false));
        for(int i=0; i<B.size();i++)
        {
            st.insert(B[i]);
        }
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i; j<n; j++)
            {
                if(i==j)
                {  
                    memo[i][j]=st.count(str.substr(i, 1))?true:false;
                    continue;
                }
                if(st.count(str.substr(i, j-i+1)))
                   { memo[i][j]=true; continue;}
                for(int k=i; k<j; k++)
                {
                    if(memo[i][k] and memo[k+1][j])
                    { memo[i][j]=true;
                    break;
                    }
                }
            }
        }
        return memo[0][n-1];
    }
};