#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to detect cycle in an undirected graph.
    bool dfs(vector<int>adj[],int s,vector<int>&visited,int parent)
    {
        visited[s]=1;
        for(auto u:adj[s])
        {
            if(visited[u]==0)
            {
                if(dfs(adj,u,visited,s))
                return true;
            }
            else if(u!=parent)
            return true;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int>visited(V+1,0);
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==0)
	        {
	            if(dfs(adj,i,visited,-1))
	            return true;
	        }

	    }
	    return false;
	}
};
