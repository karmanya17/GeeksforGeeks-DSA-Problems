{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
 int i,j;
 int lessthank=0,minswap=0;
 for(i=0;i<n;i++)
 {
     if(arr[i]<=k)
     {
         lessthank++;
     }
 }
 int res=0,count=0;
 for(i=0;i<lessthank;i++)
 {
  if(arr[i]>k)
  count++;
 }
 res=count;
 i=0;j=lessthank;
 while(j<n)
 {
     if(arr[i]>k)count--;
     if(arr[j]>k)count++;
     res=min(res,count);
     i++;j++;
 }
 return res;

}
