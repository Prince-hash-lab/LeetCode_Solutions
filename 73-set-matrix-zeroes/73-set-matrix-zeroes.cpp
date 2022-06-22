class Solution {
public:
    // bool tochange(vector<vector<int>> arr, int row, int col, int i, int j)
    // {
    //     return (i<row) and (i>=0) and (j>=0) and (j<col) and arr[i][j]!=0;
    // }
    void setZeroes(vector<vector<int>>& arr) {
        int row=arr.size(), isrow0=0;
        int col=arr[0].size(), iscol0=0;
        if(arr[0][0]==0){ isrow0=1; iscol0=1;}
        for(int i=0; i<row; i++) if(arr[i][0]==0){ iscol0=1;}
        for(int i=0; i<col; i++) if(arr[0][i]==0) { isrow0=1;}
        
        for(int i=1; i<row; i++)
        {
            for(int j=1; j<col; j++)
            {
                if(arr[i][j]==0)
                {
                    arr[i][0]=0;
                    arr[0][j]=0;
                }
            }
        }
        
        for(int i=1; i<row; i++)
        {
            if(arr[i][0]==0)
            {
                for(int j=1; j<col; j++)
                {
                   arr[i][j]=0;
                }
                
            }
        }
        
        for(int i=1; i<col; i++)
        {
             if(arr[0][i]==0)
            {
                for(int j=1; j<row ; j++)
                {
                   arr[j][i]=0;
                }
             }
        }
        
        if(iscol0==1)
        for(int i=0; i<row; i++) arr[i][0]=0;
        
        if(isrow0==1)
        for(int i=0; i<col; i++) arr[0][i]=0;
        
        
        
    }
};