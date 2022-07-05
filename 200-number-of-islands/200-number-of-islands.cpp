class Solution {
public:
    bool issafe(vector<vector<char>>& grid, int i, int j, int row, int col)
    {
        return i>=0 and i<row and j>=0 and j<col and grid[i][j]=='1';
    }
    void dfs(vector<vector<char>>& grid, int i, int j, int row, int col)
    {
        grid[i][j]='0';
        if(issafe(grid, i+1, j, row, col)) dfs(grid, i+1, j, row, col);
        if(issafe(grid, i, j+1, row, col)) dfs(grid, i, j+1, row, col);
        if(issafe(grid, i-1, j, row, col)) dfs(grid, i-1, j, row, col);
        if(issafe(grid, i, j-1, row, col)) dfs(grid, i, j-1, row, col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int row=grid.size(), col=grid[0].size();
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                if(issafe(grid, i, j, row, col))
                { dfs(grid, i, j, row, col); res++;}
            }
        return res;
    }
};