/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */


Node* merge(Node * head1,Node* head2){
    if(head1==NULL && head2==NULL)
    return NULL;
    
    if(head1==NULL){
        return head2;
    }
    
    if(head2==NULL){
        return head1;
    }
    
    
    if(head1->data<=head2->data){
        head1->bottom=merge(head1->bottom,head2);
        return head1;
    }
    
    head2->bottom=merge(head1,head2->bottom);
    return head2;
}    

  
Node *flatten(Node *root)
{
   // Your code here
   Node* newHead=root;
   Node* curNode=root;
   
   while(curNode->next!=NULL){
       newHead=merge(newHead,curNode->next);
       curNode=curNode->next;
   }
   
   return newHead;
   
   
}
