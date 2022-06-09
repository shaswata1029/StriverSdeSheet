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
        
        curNode->next=head;
        k=len-k;
        
        curNode=head;
        while(k>1){
            curNode=curNode->next;
            k--;
        }
        
        ListNode*newHead=curNode->next;
        curNode->next=NULL;
        return newHead;
        
       
        
        
        
        
        
        
        
    }
};