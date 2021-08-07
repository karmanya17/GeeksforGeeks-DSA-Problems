#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void matchPairs(char nuts[], char bolts[], int n) {
	    sort(nuts,nuts+n);
	    unordered_map<char,int>s;
	    for(int i=0;i<n;i++)
	    {
	        s[nuts[i]]=i;
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(s.find(bolts[i])!=s.end())
	        {
	            nuts[i]=bolts[i];
	        }
	    }
	}

};
