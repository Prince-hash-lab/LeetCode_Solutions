class Solution {
public:
    // int fun( vector<int> zs, vector<int> os, int i ,int m ,int n, int ln)
    // {
    //     if(i==ln) return 0;
    //     if(m<0 or n<0) return 0;
    //     if(zs[i]<=m and os[i]<=n)
    //         return max(1+fun(zs, os, i+1, m-zs[i], n-os[i], ln), fun(zs, os, i+1, m, n, ln));
    //     else
    //         return fun(zs, os, i+1, m, n, ln);
    // }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vector<int> os(sz, 0);
        vector<int> zs(sz, 0);
        
        for(int i=0; i<sz; i++)
        {
            int ln=strs[i].length();
            for(int j=0; j<ln; j++)
            {
                if(strs[i][j]=='0') zs[i]++;
                if(strs[i][j]=='1') os[i]++;
            }
        }
        // return  fun(zs, os, 0, m,n, sz);
        vector<vector<vector<int>>> temp(sz+1, vector<vector<int>>(m+1, vector<int> (n+1, 0)));
//           for(int i=1; i<sz+1; i++)
//             for(int j=0; j<m+1; j++)
//             {
//                 for(int k=0; k<n+1; k++)
//                 {
                  
//                     cout<<temp[i][j][k]<<" ";
//                 }
//                 cout<<endl;
//             }
        for(int i=1; i<sz+1; i++)
            for(int j=0; j<m+1; j++)
            {
                for(int k=0; k<n+1; k++)
                {
                    if(zs[i-1]<=j and os[i-1]<=k)
                    {
                        temp[i][j][k]=max(temp[i-1][j][k], 1+temp[i-1][j-zs[i-1]][k-os[i-1]]);
                    }
                    else 
                         temp[i][j][k]=temp[i-1][j][k];
                }
            }
        
        return temp[sz][m][n];
        
    }
};