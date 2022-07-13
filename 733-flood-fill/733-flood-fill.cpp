class Solution {
public:
    bool issafe(int i, int j, int row, int col)
    {
        return i>=0 and i<row and j>=0 and j<col;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> qu;
        int scol=image[sr][sc];
        if(scol!=color)
        {
            qu.push({sr,sc});
            image[sr][sc]=color;
        }
        int qr, qc, row=image.size(), col=image[0].size();
        while(qu.empty()==false)
        {
            qr=qu.front().first;    qc=qu.front().second;
            qu.pop();
            if(issafe(qr+1, qc, row, col ) and image[qr+1][qc]==scol) 
            {
                image[qr+1][qc]=color;
                qu.push({qr+1, qc});
            }
            if(issafe(qr, qc+1, row, col ) and image[qr][qc+1]==scol) 
            {
                image[qr][qc+1]=color;
                qu.push({qr, qc+1});
            }
            if(issafe(qr-1, qc, row, col ) and image[qr-1][qc]==scol) 
            {
                image[qr-1][qc]=color;
                qu.push({qr-1, qc});
            }
            if(issafe(qr, qc-1, row, col ) and image[qr][qc-1]==scol) 
            {
                image[qr][qc-1]=color;
                qu.push({qr, qc-1});
            }
        }
        return image;
    }
};
// const auto fast = []() 
// {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();