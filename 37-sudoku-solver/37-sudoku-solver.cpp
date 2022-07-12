
class Solution {
public:
    bool issafe(vector<vector<char>>& brd, int row, int col, char val)
    {
        for(int i=0; i<9; i++)
        {
            if(brd[row][i]==val) return false;
            if(brd[i][col]==val) return false;
        }
//         int brow=floor(((float)row/3))*3, trow=ceil(((float)row/3))*3, bcol=floor(((float)col/3))*3, tcol=ceil(((float)col/3))*3;
 
//         for(int i=brow; i<trow; i++)
//         {
//             for(int j=bcol; j<tcol; j++)
//                  if(brd[i][j]==val) return false;
//         }
        int rs=row-row%3, cs=col-col%3;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
            {
                if(brd[i+rs][j+cs]==val) return false;
            }
        return true;
    }
    bool ssu(vector<vector<char>>& brd)
    {
        int i,j;
        int fg=0;
        for(i=0; i<9 ; i++)
        {
            for(j=0; j<9; j++)
            {
                if(brd[i][j]=='.')
                {   fg=1;
                    break;
                }
            }
            if(fg==1) break;
        }
        if(i==9 and j==9) return true;
        
        // cout<<i<<" "<<j<<endl;
        for(char x='1'; x<='9'; x++)
        { 
            if(issafe(brd, i, j, x))
            {
                brd[i][j]=x;
                if(ssu(brd)) return true;
                brd[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& brd) {
        ssu(brd);
    }
};
const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();