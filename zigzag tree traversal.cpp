#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

vector <int> zigZagTraversal(Node* root);

int main()
{
    int t;
    scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = zigZagTraversal(root);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout<<endl;
  }
  return 0;
}
// Contributed by: Hashit Sidhwa

// } Driver Code Ends


//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

//Function to store the zig zag order traversal of tree in a list.
vector <int> zigZagTraversal(Node* root)
{
// 	vector<int>res;
// 	stack<Node*>st1;
// 	stack<Node*>st2;
// 	st1.push(root);
// 	Node*temp;
// 	while(!st1.empty()||!st2.empty())
// 	{
// 	    while(!st1.empty())
// 	    {
// 	       temp=st1.top();
// 	       st1.pop();
// 	       res.push_back(temp->data);
// 	       if(temp->left)
// 	       st2.push(temp->left);
// 	       if(temp->right)
// 	       st2.push(temp->right);
// 	    }
// 	    while(!st2.empty())
// 	    {
// 	        temp=st2.top();
// 	        st2.pop();
// 	        res.push_back(temp->data);
// 	        if(temp->right)
// 	        st1.push(temp->right);
// 	        if(temp->left)
// 	        st1.push(temp->left);
// 	    }
// 	}
// 	return res;

vector<int>res;
stack<Node*>currentlevel;
stack<Node*>nextlevel;
if(!root)
return res;
currentlevel.push(root);
bool lefttoright=true;
while(!currentlevel.empty())
{
    Node*temp=currentlevel.top();
    currentlevel.pop();
    if(temp)
    {
        res.push_back(temp->data);
        if(lefttoright)
        {
            if(temp->left)
            nextlevel.push(temp->left);
            if(temp->right)
            nextlevel.push(temp->right);
        }
        else
        {
            if(temp->right)
            nextlevel.push(temp->right);
            if(temp->left)
            nextlevel.push(temp->left);
        }
    }
    if(currentlevel.empty())
    {
        lefttoright=!lefttoright;
        swap(currentlevel,nextlevel);
    }
}
return res;

}
