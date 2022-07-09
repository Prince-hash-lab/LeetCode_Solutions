// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int a1, a2;
        stack<int> st;
        for(int i=0; i<n; i++) st.push(i);
        while(!st.empty())
        {
            a1=st.top();  st.pop();
            if(st.empty()) break;
            a2=st.top(); st.pop();
            if(M[a1][a2]==0 and M[a2][a1]==0) continue;
            else if(M[a1][a2]==0) st.push(a1);
            else if(M[a2][a1]==0) st.push(a2);
            if(st.empty()) return -1;
        }
        for(int i=0; i<n; i++)
        {
            if(i!=a1 and (!M[i][a1] or M[a1][i])) return -1;
            
        }
        return a1;
        // code here 
    }
};




// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends