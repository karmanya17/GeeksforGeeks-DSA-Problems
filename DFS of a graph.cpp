#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void dfsRec(vector<int>adj[],int s,vector<int>&vis,vector<int>&dfs)
	{
	    vis[s]=1;
	    dfs.push_back(s);
	    for(int i:adj[s])
	    if(vis[i]==0)
	    dfsRec(adj,i,vis,dfs);

	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{

	   vector<int>dfs;
	   vector<int>vis(V,0);
	   dfsRec(adj,0,vis,dfs);
	   return dfs;
	}
};
