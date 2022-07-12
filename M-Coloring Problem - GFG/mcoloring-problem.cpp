// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool issafe(bool graph[101][101],  vector<int> &gc,  int m, int n, int i, int col)
{
    for(int v=0; v<n; v++)
    {
        if(graph[i][v]==1 and gc[v]==col) return false;
    }
    return true;
}
bool colg(bool graph[101][101], vector<int> &gc,  int m, int n, int i)
{
    if(i==n) return  true;
    // int col=0;
    for(int col=0; col<m; col++)
    {
        if(issafe(graph, gc, m, n, i, col))
        {
            gc[i]=col;
            if(colg(graph, gc, m, n, i+1)) return true;
            gc[i]=-1;
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> gc(n, -1);
    // vector<int> vis(n, 0);
    // for(int i=0; i<n; i++)
    // {
    //     if(gc[i]==-1 and !colg(graph, gc, m , n , i);)
    //     {
    //         return false;
    //     }
    // }
    if(!colg(graph, gc, m , n , 0)) return false;
    return true;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends