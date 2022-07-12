class Solution {
public:
    int search(vector<int>& arr, int t) {
        int l=0, n=arr.size(), h=n-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(arr[m]==t) return m;
            else if(arr[m]>=arr[l] and arr[m]>=arr[h])
            {
                if(t<=arr[h] or t>arr[m]) l=m+1;
                else h=m-1;
            }
            else if(arr[m]<=arr[l] and arr[m]<=arr[h])
            {
                if(t<=arr[h] and t>arr[m]) l=m+1;
                else h=m-1;
            }
            else if(arr[m]>=arr[l] and arr[m]<=arr[h])
            {
                if(arr[m]>t) h=m-1;
                else l=m+1;
            }
            else if(arr[m]<=arr[l] and arr[m]>=arr[h])
            {
                 if(arr[m]>t)l=m+1;
                    else  h=m-1;
            }
        }
        return -1;
    }
};