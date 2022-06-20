class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int maxm=-1;
        int temp;
        for(int i=n-1; i>=0; i--)
        {
            if(i==n-1) swap(arr[i],maxm);
            else {
                temp=maxm;
                maxm=max(arr[i], maxm);
                arr[i]=temp;
                         }
        }
        return arr;
    }
};