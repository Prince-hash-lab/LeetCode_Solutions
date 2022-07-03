// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    // void maxmeet(vector<pair<int,int>> temp, int &ans, int n, int i, int val)
    // {
    //     if(i==n) return;
    //     maxmeet(temp, ans,n, i+1, val)
        
    // }
    static bool compare(pair<int,int> p1, pair<int,int> p2)
    {
        return p1.second<p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> temp;
        if(n==0 or n==1) return n;
        for(int i=0; i<n; i++)
        {
            temp.push_back({start[i], end[i]});
        }
        sort(temp.begin(), temp.end(), compare);
        int ans=1, pind=0;
        for(int i=1; i<n; i++)
        {
            if(temp[i].first>temp[pind].second)
            {
                ans++; pind=i;
            }
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
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends