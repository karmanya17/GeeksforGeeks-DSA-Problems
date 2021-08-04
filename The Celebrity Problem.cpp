#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)
    {
        int ans;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        int i=0;
        while(st.size()>=2)
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(M[a][b]==1)
            {
                st.push(b);
            }
            else if(M[b][a]==1)
            {
                st.push(a);
            }
        }
        int cel=st.top();
        for(int i=0;i<n;i++)
        {
            if(i!=cel){
            if(M[i][cel]==0 || M[cel][i]==1)
            return -1;
            }
        }
        return cel;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
