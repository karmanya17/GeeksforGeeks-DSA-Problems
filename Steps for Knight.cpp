#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	bool isvalid(int x,int y,int n)
	{
	    return (x>=0 && y>=0 && x<n && y<n);
	}
	int bfs(int x,int y,int tx,int ty,int N)
	{
	    int dx[]={-2,-1,1,2,2,1,-1,-2};
	    int dy[]={1,2,2,1,-1,-2,-2,-1};

	   int steps=0;
	    vector<vector<bool>>vis(N+1,vector<bool>(N+1,false));
	    queue<pair<int,int>>q;
	    q.push({x,y});
	    vis[x][y]=1;
	    while(!q.empty())
	    {
	        int posCount=q.size();
	        for(int count=0;count<posCount;count++)
	        {
	            pair<int,int>temp=q.front();
	            q.pop();
	            if(temp.first==tx && temp.second==ty)
	        {
	            return steps;
	        }

	            for(int i=0;i<8;i++)
	        {
	            int newX=temp.first+dx[i];
	            int newY=temp.second+dy[i];
	            if(isvalid(newX,newY,N) && vis[newX][newY]==false)
	            {
	                vis[newX][newY]=true;
	                q.push({newX,newY});
	            }
	        }
	        }

	        steps++;
	    }
	    return -1;
	}
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{


	   return bfs(KnightPos[0]-1,KnightPos[1]-1,TargetPos[0]-1,TargetPos[1]-1,N);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
