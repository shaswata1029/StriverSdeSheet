/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        
        ListNode *curNode=head;
        int len=1;
        
        while(curNode->next!=NULL){
            len++;
            curNode=curNode->next;
        }
        
         k=k%len;
        if(k==0)
            return head;    
        
//         Making the last node pointing to the head node
        curNode->next=head;
//         Doing this so we know the node which will point to NULL and its next node will be the new head.
        k=len-k;
        
        while(k>0){
            curNode=curNode->next;
            k--;
        }
        
        ListNode*newHead=curNode->next;
        curNode->next=NULL;
        return newHead;
        
       
        
        
        
        
        
        
        
    }
};