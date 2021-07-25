#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>distto(V+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push(make_pair(S,0));
        distto[S]=0;
        while(!pq.empty())
        {
            int prev=pq.top().first;
            int dist=pq.top().second;
            pq.pop();
            for(auto v:adj[prev])
            {
                int next=v[0];
                int nextdist=v[1];
                if(distto[next]>distto[prev]+nextdist)
                {
                    distto[next]=distto[prev]+nextdist;
                    pq.push(make_pair(next,distto[next]));
                }
            }
        }
        return distto;
    }

};
