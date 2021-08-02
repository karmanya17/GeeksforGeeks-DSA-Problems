#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int node,bool graph[101][101],int v,int colour[],int col)
{
    for(int k=0;k<v;k++)
    {
        if(k!=node && graph[k][node]==1 && colour[k]==col)
        return false;
    }
    return true;
}
bool solve(int node,bool graph[101][101],int m,int colour[],int v)
{
    if(node==v)
    return true;
    for(int i=1;i<=m;i++)
    {
        if(isSafe(node,graph,v,colour,i))
        {
            colour[node]=i;
            if(solve(node+1,graph,m,colour,v)) return true;
            colour[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    int colour[V]={0};
    if(solve(0,graph,m,colour,V))
    return true;
    return false;

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
