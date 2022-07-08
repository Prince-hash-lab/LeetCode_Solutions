class Solution {
public:
    bool issafe(vector<vector<int>>& grid, int row, int col, int i, int j)
    {
        return i>=0 and j>=0 and i<row and j<col and grid[i][j]==1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size(), col=grid[0].size();
        queue<pair<int, int>> qu;
        pair<int, int> temp;
        int cnt=0, n=0, ti, tj, tot1=0;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]==2) 
                {  qu.push({i, j}); }
                else if(grid[i][j]==1) tot1++;
                
            }
        while(!qu.empty())
        {
            n=qu.size();
            for(int i=0; i<n; i++)
            {
                temp=qu.front();
                qu.pop();
                ti=temp.first;  tj=temp.second;
                if(issafe(grid, row, col, ti, tj+1)) {grid[ti][tj+1]=2; qu.push({ti, tj+1}); tot1--;}
                if(issafe(grid, row, col, ti+1, tj)) {grid[ti+1][tj]=2; qu.push({ti+1, tj}); tot1--;}
                if(issafe(grid, row, col, ti, tj-1)) {grid[ti][tj-1]=2; qu.push({ti, tj-1}); tot1--;}
                if(issafe(grid, row, col, ti-1, tj)) {grid[ti-1][tj]=2; qu.push({ti-1, tj}); tot1--;}
                
            }
            if(qu.size()!=0) cnt++;
            
        }
        if(tot1!=0) return -1;
        return cnt;
    }
};
const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();