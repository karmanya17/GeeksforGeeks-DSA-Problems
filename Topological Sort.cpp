#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(int s,vector<bool>&vis,vector<int>adj[],stack<int>&st)
	{
	    vis[s]=true;
	    for(auto v:adj[s])
	    {
	        if(vis[v]==false)
	        {
	            dfs(v,vis,adj,st);
	        }
	    }
	    st.push(s);
	}
	vector<int> topoSort(int V, vector<int> adj[])
	{
        	   // BFS
// 	    vector<int>res;
// 	    vector<int>indegree(V);
// 	    for(int i=0;i<V;i++)
// 	    {
// 	        for(auto u:adj[i])
// 	        {
// 	            indegree[u]++;
// 	        }
// 	    }

// 	queue<int>q;
// 	for(int i=0;i<V;i++)
// 	{
// 	    if(indegree[i]==0)
// 	    {
// 	        q.push(i);
// 	    }
// 	}
// 	while(!q.empty())
// 	{
// 	    int u=q.front();
// 	    q.pop();
// 	    res.push_back(u);
// 	    for(auto v:adj[u])
// 	    {
// 	        indegree[v]--;
// 	        if(indegree[v]==0)
// 	        {
// 	            q.push(v);
// 	        }
// 	    }
// 	}
// 	return res;

        vector<bool>vis(V+1,false);
        vector<int>res;
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                dfs(i,vis,adj,st);
            }
        }
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            res.push_back(node);
        }
        return res;
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
