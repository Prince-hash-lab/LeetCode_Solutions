class Solution {
public:
    // bool dfs( vector<int> adj[], vector<bool> &vis, vector<bool> &recst,int sr)
    // {
    //     vis[sr]=true;
    //     recst[sr]=true;
    //     // if(adj[sr].size()>0)
    //     for(auto x : adj[sr])
    //     {
    //         if(!vis[x] and dfs(adj, vis,recst,  x)) return true;
    //         else if(recst[x]) return true;
    //     }
    //     recst[sr]=false;
    //     return false;
    // }
    bool canFinish(int V, vector<vector<int>>& edges) {
       vector<int> adj[V];
       int nedge=edges.size();
        for(int i=0; i<nedge; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
         vector<int> indeg(V, 0);
        int count=0;
          for(int i=0; i<V; i++)
	    {
	        for(int x : adj[i]) indeg[x]++;
	    }
	   queue<int> qu;
	    for(int i=0; i<V; i++) if(indeg[i]==0) qu.push(i);
	    while(!qu.empty())
	    {
	        int top=qu.front();
	        qu.pop();
            count++;
	        // ans.push_back(top);
	        for(int x: adj[top]) 
	        {  indeg[x]--;
	            if(indeg[x]==0) qu.push(x);
	        }
	    }
        
        return count==V;
//         for(int i=0; i<v; i++)
//         {
//             if(!vis[i] and dfs(adj, vis,recst,  i)) return false;
//         }
        return true;
    }
};