// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void dfs(vector<int> adj[], vector<int> &vis, int V , int sr, bool &res, int prev)
    {
        if(vis[sr]) {res=true; return ;}
        vis[sr]=1;
        for(auto x: adj[sr])
            if(x!=prev)
                dfs(adj, vis, V, x, res, sr);
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        if(V==0 )return true;
        vector<int> vis(V, 0);
        bool res=false;
        for(int i=0; i<V; i++)
        {
            if(!vis[i])  dfs(adj, vis, V, i, res, -1);
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends