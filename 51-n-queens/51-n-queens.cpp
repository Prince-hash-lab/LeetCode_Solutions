class Solution {
public:
    bool issafe(vector<string> ans, int n, int i, int j)
    {
        if(i<0 or j<0 or i>=n or j>=n) return false;
        for(int row=0; row<n; row++)
            if(ans[row][j]=='Q') return false;
        for(int col=0; col<n; col++)
            if(ans[i][col]=='Q') return false;
        int row=i, col=j;
        while(row>=0 and col>=0)
        {
            if(ans[row--][col--]=='Q') return false;
        }
        row=i; col=j;
        while(row<n and col<n)
        {
             if(ans[row++][col++]=='Q') return false;
        }
        row=i; col=j;
        while(row>=0 and col<n)
        {
             if(ans[row--][col++]=='Q') return false;
        }
        row=i; col=j;
        while(row<n and col>=0)
        {
             if(ans[row++][col--]=='Q') return false;
        }
        return true;
    }
    
    bool findsol(vector<vector<string>> &brd, vector<string>& psol,int n, int k)
    {
         if(k==n) 
         {
             brd.push_back(psol);
             return true;
         }
        // for(int i=k; k<n; k++)
        // {
            for(int j=0; j<n; j++)
            {
                if(issafe(psol, n, k, j))
                {
                    psol[k][j]='Q';
                    findsol(brd, psol, n, k+1);
                    psol[k][j]='.';
                }
            // }
        }
        
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> brd;
        vector<string> psol;
        string dot;
        for(int i=0; i<n; i++)
        {   dot="";
            for(int j=0; j<n; j++)
                dot+=".";
            psol.push_back(dot);
        }
        findsol(brd,psol, n, 0);
        return brd;
    }
};
const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();