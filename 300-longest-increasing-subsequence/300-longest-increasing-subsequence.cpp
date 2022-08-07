#define vi  vector<int>
#define vvi  vector<vector<int>>

class Solution {
public:
    // int lis(vi nums,int i,int n, int pi,vector<vector<int>> &tp )
    // {
    //     if(i==n) return 0;
    //     if(tp[i][pi+1]!=-1) return tp[i][pi+1];
    //     int len=lis(nums, i+1, n, pi, tp);
    //     if(pi==-1 or nums[pi]<nums[i])
    //     {
    //         // if(tp[i+1][i+1]==-1)
    //         //     tp[i+1][i+1]=lis(nums, i+1, n, i, tp)+1;
    //         len=max(len,lis(nums, i+1, n, i, tp)+1);
    //     }
    //         // len=max(len, 1+lis(nums, i+1, n, i, tp));
    //     return tp[i][pi+1]=len; 
    // }
    int lengthOfLIS(vi& nums) {
        int n=nums.size();
        vi res;
        res.push_back(nums[0]);
        for(int i=1; i<n; i++)
        {
            if(nums[i]>res[res.size()-1]) res.push_back(nums[i]);
            else 
            {
                res[lower_bound(res.begin(), res.end(), nums[i])-res.begin()]=nums[i];
            }
        }
        return res.size();
        
        
        
        // vector<vector<int>> tp(n, vector<int> (n+1, -1));
        // return lis(nums, 0, n, -1, tp);
        // for(int i=0; i<n+1; i++)
        // {
        //     cout<<i<<" ";
        //     for(int j=0; j<n+1; j++)
        //         cout<<tp[i][j]<<" ";
        //     cout<<endl;
        // }
        // return ans;
        
    }
};