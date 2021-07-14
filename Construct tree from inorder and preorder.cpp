#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int idx=0;
    int search(int in[],int start,int end,int curr)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i]==curr)
            return i;
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int start,int end)
    {
        if(start>end)
        return NULL;
        int curr=pre[idx++];
        Node * node= new Node(curr);
        if(start==end)
        return node;
        int pos=search(in,start,end,curr);
        node->left=solve(in,pre,start,pos-1);
        node->right=solve(in,pre,pos+1,end);
        return node;

    }
    Node* buildTree(int in[],int pre[], int n)
    {
        idx=0;
        Node *head=solve(in,pre,0,n-1);
        return head;
    }
};
