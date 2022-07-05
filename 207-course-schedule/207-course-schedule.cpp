class Solution {
public:
    bool dfs( vector<int> adj[], vector<bool> &vis, vector<bool> &recst,int sr)
    {
        vis[sr]=true;
        recst[sr]=true;
        // if(adj[sr].size()>0)
        for(auto x : adj[sr])
        {
            if(!vis[x] and dfs(adj, vis,recst,  x)) return true;
            else if(recst[x]) return true;
        }
        recst[sr]=false;
        return false;
    }
    bool canFinish(int v, vector<vector<int>>& edges) {
       vector<int> adj[v];
       int nedge=edges.size();
        for(int i=0; i<nedge; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool> vis(v, false);
        vector<bool> recst(v, false);
        for(int i=0; i<v; i++)
        {
            if(!vis[i] and dfs(adj, vis,recst,  i)) return false;
        }
        return true;
    }
};