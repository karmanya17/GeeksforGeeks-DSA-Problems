#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node*next,*prev;

  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
struct node* update(struct node*start,int p);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        struct node*start = NULL;
        struct node* cur = NULL;
        struct node* ptr = NULL;

        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ptr=new node(a);
            ptr->data=a;
            ptr->next=NULL;
            ptr->prev=NULL;
            if(start==NULL)
            {
                start=ptr;
                cur=ptr;
            }
            else
            {
                cur->next=ptr;
                ptr->prev=cur;
                cur=ptr;
            }
        }
        struct node*str=update(start,p);
        while(str!=NULL)
        {
            cout<<str->data<<" ";
            str=str->next;
        }
        cout<<endl;
    }
}

 // } Driver Code Ends
//User function Template for C++

/*
struct node
{
  int data;
  struct node*next,*prev;

  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

struct node*update(struct node*head,int p)
{
    //Add your code here
    int count=1;
    struct node*curr=head,*newhead=NULL;

    while(count<p&&curr!=NULL)
    {
        curr=curr->next;
        count++;
    }
   
    newhead=curr;

    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=head;
    head->prev=curr;
    head=newhead->next;

    newhead->next=NULL;
    head->prev=NULL;
    return head;
}

// { Driver Code Starts.
  // } Driver Code Ends
