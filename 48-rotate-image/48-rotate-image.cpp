class Solution {
public:
    void rotate(vector<vector<int>>& mx) {
        int row=mx.size(), col=mx[0].size();
        for(int i=0; i<row; i++)
        {
            for(int j=i+1; j<col; j++)
                swap(mx[i][j], mx[j][i]);
        }
        
        for(int i=0 ;i<row; i++)
        {
            int low=0, high=col-1;
            while(low<high)
            {
                swap(mx[i][low++], mx[i][high--]);
            }
        }
    }
};