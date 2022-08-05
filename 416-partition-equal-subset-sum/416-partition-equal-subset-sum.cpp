#define ll long long
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        ll n=nums.size();
        long long sum=0;
        for(int i=0; i<n; i++)
            sum+=nums[i];
        if(sum%2!=0) return false;
        sum/=2;
        vector<vector<ll> > tp(n+1, vector<ll> (sum+1, 0));
        for(int i=0; i<n+1; i++)
            tp[i][0]=1;
        for(int i=1; i<sum+1; i++)
            tp[0][i]=0;
        for(int i=1; i<n+1; i++)
            for(int j=1; j<sum+1; j++)
            {
                if(nums[i-1]<=j)
                    tp[i][j]=(tp[i-1][j]+tp[i-1][j-nums[i-1]])%1000000;
                else 
                    tp[i][j]=tp[i-1][j];
            }
        
        if(tp[n][sum]) return true;
        return false;
        
        
    }
};