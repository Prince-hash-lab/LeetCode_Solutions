// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// void par(vector<int> a, int n)
// {
//     for(int i=0; i<n; i++) cout<<a[i]<<" ";
//     cout<<endl;
// }

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> ans(n, 0), nsml(n, 0), psml(n,0);
        stack<int> st;
        //finding prev smaller element for each element
        for(int i=0; i<n; i++)
       {
            while(!st.empty() and arr[st.top()]>=arr[i]) st.pop();
            psml[i]=(st.empty()?-1:st.top());
            st.push(i);
       }
        while(!st.empty()) st.pop();
        // par(psml, n);
        // finding next smaller element for each element
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() and arr[st.top()]>=arr[i]) st.pop();
            nsml[i]=(st.empty()?n:st.top());
            st.push(i);
        }
        //  par(nsml, n);
        //calculating max of min value for each window size 
        for(int i=0; i<n; i++)
        {
            ans[nsml[i]-psml[i]-2]=max(arr[i], ans[nsml[i]-psml[i]-2]);
        }
    //       for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    // cout<<endl;
        for(int i=n-2;i>=0; i--)
        {
            ans[i]=max(ans[i],ans[i+1]);
        }
        return ans;
        // Your code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends