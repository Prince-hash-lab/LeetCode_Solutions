class Solution {
public:
    int trap(vector<int>& arr) {
        int low =1, high=arr.size()-2, lhigh=arr[0], rhigh=arr[high+1];
        int wtr=0;
        while(low<=high)
        {
            lhigh=max(lhigh, arr[low]);
            rhigh=max(rhigh, arr[high]);
            if(lhigh>=rhigh)
            {
                wtr+=rhigh-arr[high];
                high--;
            }
            else if(rhigh>lhigh)
            {
                    wtr+=lhigh-arr[low];
                    low++;
            }
        }
        return wtr;
    }
};