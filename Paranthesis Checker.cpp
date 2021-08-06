#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool isvalid(stack<char>&st,char ch)
    {
        if(st.size()==0)
        return false;
        else if(st.top()!=ch)
        return false;
        else{
        st.pop();
        return true;
        }
    }
    bool ispar(string x)
    {
        stack<char>st;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='{'||x[i]=='('||x[i]=='[')
            {
                st.push(x[i]);
            }
            else if(x[i]==')')
            {
                if(!isvalid(st,'('))
                return false;
            }
            else if(x[i]==']')
            {
              if(!isvalid(st,'['))
                return false;
            }
            else if(x[i]=='}')
            {
               if(!isvalid(st,'{'))
                return false;
            }

        }
            if(st.size()==0)
            return true;
            else
            return false;

    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
