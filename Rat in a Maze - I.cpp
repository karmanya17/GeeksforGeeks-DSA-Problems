// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int x,int y,int n)
    {
        return (x>=0&&y>=0&&x<n&&y<n);
    }
    void dfs(int x,int y,vector<vector<int>>&m,vector<vector<bool>>&vis,vector<string>&res,vector<char>&temp,int n)
    {
        if(x==n-1 && y==n-1)
        {
           string t;
           for(int i=0;i<temp.size();i++)
           {
               t.push_back(temp[i]);
           }
           res.push_back(t);
           return;
        }
        vis[x][y]=true;
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int X=x+dx[i];
            int Y=y+dy[i];
            if(i==0) temp.push_back('L');
            if(i==1){
            temp.pop_back();
            temp.push_back('U');
            }
            if(i==2){
                temp.pop_back();
                temp.push_back('R');
            }
            if(i==3)
            {
                temp.pop_back();
                temp.push_back('D');
            }
            if(isSafe(X,Y,n)&&m[X][Y]==1&&vis[X][Y]==false)
            {
                
                dfs(X,Y,m,vis,res,temp,n);
            }
            
        }
        temp.pop_back();
        vis[x][y]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string>res;
        vector<char>temp;
        if(m[0][0]==0)
        return res;
        vector<vector<bool>>vis(n,vector<bool>(n, false));
    
        dfs(0,0,m,vis,res,temp,n);
        
        sort(res.begin(),res.end());
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
