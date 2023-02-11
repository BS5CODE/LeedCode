//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};


/* Function to get the middle of the linked list*/
bool isCircular(struct Node *head);

/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){

        cin>>n>>k;
	    Node *head=NULL, *tail = NULL;
	    int x;
	    cin >> x;
	    head = new Node(x);
	    tail = head;
	    for(int i=0;i<n-1;i++)
	    {
	        cin>>x;
	        tail -> next = new Node(x);
	        tail = tail -> next;
	    }
        if (k==1 && n >= 1)
              tail->next = head;


    printf("%d\n", isCircular(head));
    }
    return 0;
}


// } Driver Code Ends


/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 
*/

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   // Your code here
//   Node *fast=head;
//   Node *slow=head;
   
//   if(head==NULL) return 0;
   
//   while(true){
//       if(fast==NULL || fast->next==NULL) return 0;
       
//       else if(fast==slow || fast->next==slow) return 1;
       
//       else {slow = slow->next; fast = fast->next->next; }
//   }


 Node* slow,*fast;
  slow=head;
  fast=head->next;
  //if linked list is empty it returns true as its entirely null.
  if(head==NULL)
  return true;
  while(true)
  { //fast ptr traverses quickly so If its not circular then it reaches or points to null.
    if(fast==NULL||fast->next==NULL)
    {
    return false;
    }
    //when circular fast meets or points to slow pointer while traversing
    else if(slow==fast||fast->next==slow)
    {
    return true;
    }
    //for moving forward through linked list.
    else
    {
    slow=slow->next;
    //fast traverses way ahead so it distinguishes loops out of circular list.
    fast=fast->next->next;
    }
  }
}
