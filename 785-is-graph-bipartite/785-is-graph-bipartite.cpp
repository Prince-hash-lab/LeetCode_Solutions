class Solution {
public:
    
//     void dfs(vector<vector<int>>& graph,vector<bool> &vis, int sr, bool &res)
//     {
//         vis[sr]=true;
//         for(int i=0; i< graph[sr].size()-1; i++)
//         {
//             int x=graph[sr][i];
//             if(!vis[x]) 
//             {
//                 int y=(graph[sr].back()==-1) ? -2 :-1;
//                 graph[x].push_back(y);
//                 dfs(graph, vis, x, res);
//             }
//             else if(graph[x].size()>0 and graph[x].back()==graph[sr].back())
//                 res=false;
            
//         }
//     }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n, 0);
        // bool res=true;
        queue<int> qu;
        int sr;
        for(int i=0; i<n; i++)
            if(!vis[i])
            {
                qu.push(i);
                vis[i]=1;
                while(!qu.empty())
                {
                    sr=qu.front();
                    qu.pop();
                    for(auto x: graph[sr])
                    {
                         if(!vis[x]) 
                            {
                                int y=(vis[sr]==1) ? 2 :1;
                                vis[x]=y;
                                qu.push(x);
                            }
                            else if(vis[x]==vis[sr])
                                   return false;
                    }
                }
                
            }
        return true;
    }
};