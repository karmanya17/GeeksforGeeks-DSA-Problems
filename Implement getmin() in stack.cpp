#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends

int mi=99999;
void push(stack<int>& s, int a){
	if(s.size()==0)
	{
	    s.push(a);
	    mi=a;
	}
	else if(a>=mi)
	{
	    s.push(a);
	}
	else
	{
	    s.push(a+a-mi);
	    mi=a;
	}
}

bool isFull(stack<int>& s,int n){
	if(s.size()==n)
	return true;
	else
	return false;
}

bool isEmpty(stack<int>& s){
	if(s.size()==0)
	return true;
	else
	return false;
}

int pop(stack<int>& s){
	int v=s.top();
	if(v>=mi)
	{
	    s.pop();
	}
	else
	{
	    int y=2*mi - v;
	    s.pop();
	    mi=y;
	}
}

int getMin(stack<int>& s){
	return mi;
}
