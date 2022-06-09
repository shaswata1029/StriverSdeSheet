/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)
            return NULL;
        
        Node*curNode=head;
        
        while(curNode!=NULL){
            Node *newNode=new Node(curNode->val);
            newNode->next=curNode->next;
            curNode->next=newNode;
            curNode=newNode->next;
        }
        
        curNode=head;
        while(curNode!=NULL){
            curNode->next->random=(curNode->random==NULL?NULL:curNode->random->next);
            curNode=curNode->next->next;
        }
        
        curNode=head;
        
        Node*nextNode=NULL;
        Node*newHead=head->next;
        
        while(curNode!=NULL){
            nextNode=curNode->next;
            curNode->next=(nextNode==NULL?NULL:nextNode->next);
            curNode=nextNode;
        }
        
        return newHead;
        
    }
};