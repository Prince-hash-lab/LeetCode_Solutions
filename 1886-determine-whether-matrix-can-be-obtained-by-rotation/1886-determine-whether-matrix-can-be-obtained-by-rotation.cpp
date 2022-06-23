class Solution {
public:
    bool findRotation(vector<vector<int>>& mx, vector<vector<int>>& target) {
        int row=mx.size(), col=mx[0].size();
        
    for(int times=0; times<4; times++)
    {
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
        int flag=0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
                if(mx[i][j]!=target[i][j])
                {
                    flag=1;
                    break;
                }
        }
        if(flag==0) return true;
        
    }
        return false;
    }
};