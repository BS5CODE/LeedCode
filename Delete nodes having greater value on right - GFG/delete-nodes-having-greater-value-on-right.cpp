//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *Reverse(Node *head)
    {
        Node *p,*curr,*n;
        curr=head;
        p=NULL;
        while(curr!=NULL){
            n=curr->next;
            curr->next=p;
            p=curr;
            curr=n;
        }
        head = p;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        Node *newhead = Reverse(head);
        Node *p;  
        p = newhead;
        int max=INT_MIN;
        Node *dummy=(struct Node*)malloc(sizeof(struct Node));
        Node *d=dummy;  
        
        while(p!=NULL)
        {
            if(p->data >= max)
            {
                max=p->data;
                d->next=p;
                d=d->next;
            }
            p=p->next;
        }
        d->next=NULL;
        Node *result = Reverse(dummy->next);
        return result;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends