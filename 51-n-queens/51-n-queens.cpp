class Solution {
public:
    bool findsol(vector<vector<string>> &brd, vector<string>& psol, int n, int k,vector<int> &lrow, vector<int> &ldia,vector<int> &rdia)
    {
         if(k==n) 
         {
             brd.push_back(psol);
             return true;
         }
        
            for(int j=0; j<n; j++)
            {
                if(lrow[j]==0 and ldia[k+j]==0 and rdia[n-1+j-k]==0)
                {
                    lrow[j]=1;
                    ldia[k+j]=1;
                    rdia[n-1+j-k]=1;
                    psol[k][j]='Q';
                    findsol(brd, psol, n, k+1, lrow, ldia, rdia);
                    psol[k][j]='.';
                    lrow[j]=0 ;
                    ldia[k+j]=0;
                    rdia[n-1+j-k]=0;
                }
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
        vector<int> lrow(n, 0), ldia(2*n-1, 0),rdia(2*n-1, 0);
        findsol(brd,psol, n, 0, lrow, ldia, rdia);
        return brd;
    }
};
const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();