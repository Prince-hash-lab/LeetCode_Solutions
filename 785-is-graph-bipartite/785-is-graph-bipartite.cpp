class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,vector<bool> &vis, int sr, bool &res)
    {
        vis[sr]=true;
        for(int i=0; i< graph[sr].size()-1; i++)
        {
            int x=graph[sr][i];
            if(!vis[x]) 
            {
                int y=(graph[sr].back()==-1) ? -2 :-1;
                graph[x].push_back(y);
                dfs(graph, vis, x, res);
            }
            else if(graph[x].size()>0 and graph[x].back()==graph[sr].back())
                res=false;
            
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n, false);
        bool res=true;
        for(int i=0; i<n; i++)
            if(!vis[i])
            {
                graph[i].push_back(-1);
                dfs(graph, vis,i, res);
                
            }
        return res;
    }
};