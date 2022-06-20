class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int sz=arr.size(), maxdif=0, maxval=arr[sz-1];
        for(int i=sz-2; i>=0; i--)
        {
            if(maxval>arr[i])
                maxdif=max(maxdif, maxval-arr[i]);
            maxval=max(maxval, arr[i]);
        }
        return maxdif;
    }
};