// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
     Node*reverse(Node*head)
    {
        Node*prev=NULL;
        Node*next=NULL,*curr=head;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        int sum=0;
        int carry=0;
        struct Node*temp;
        struct Node*res=NULL;
        struct Node*curr=NULL;
        while(first!=NULL || second!=NULL)
        {
            sum=carry+(first?first->data:0)+(second?second->data:0);
            
            carry=(sum>=10)?1:0;
            sum=sum%10;
            temp=new Node(sum);
            if(res==NULL)
            {
                res=temp;
            }
            else{
               curr->next=temp; 
            }
            curr=temp;
            if(first) first=first->next;
            if(second) second=second->next;

        }
        if(carry>0)
        {
            temp=new Node(1);
            curr->next=temp;
            curr=temp;
        }
        res=reverse(res);
        return res;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
