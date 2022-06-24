class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row=mat.size(), col=mat[0].size();
        int i=0, j=col-1;
        while(j>=0 and i<row)
        {
            if(mat[i][j]==target) return true;
            else if(mat[i][j]<target) i++;
            else j--;
        }
        return false;
    }
};