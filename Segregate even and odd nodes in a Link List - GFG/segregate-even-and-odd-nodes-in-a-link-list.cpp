// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
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
class Solution{
public:
    Node* divide(int N, Node *head){
        if(head==NULL || head->next==NULL)
            return head;
        
        Node*curNode=head;
        Node *prevEvenNode=NULL,*headEvenNode=NULL,*prevOddNode=NULL,*headOddNode=NULL;
        
        while(curNode!=NULL){
            int val=curNode->data;
            
            if(val%2==0){
                if(prevEvenNode==NULL)
                    headEvenNode=curNode;
                else
                    prevEvenNode->next=curNode;
                
                while(curNode->next!=NULL && (curNode->next->data)%2==0)
                    curNode=curNode->next;
                
                prevEvenNode=curNode;
                curNode=curNode->next;
                prevEvenNode->next=NULL;
            }
            else{
                if(prevOddNode==NULL)
                    headOddNode=curNode;
                else
                    prevOddNode->next=curNode;
                
                while(curNode->next!=NULL && (curNode->next->data)%2==1)
                    curNode=curNode->next;
                
                prevOddNode=curNode;
                curNode=curNode->next;
                prevOddNode->next=NULL;
            }   
        }
        
        if(headEvenNode==NULL)
            return headOddNode;
        
        if(headOddNode==NULL)
            return headEvenNode;
        
        prevEvenNode->next=headOddNode;
        return headEvenNode;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends