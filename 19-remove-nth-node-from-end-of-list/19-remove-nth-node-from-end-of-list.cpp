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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* prevNode=NULL;
        ListNode *fast=head,*slow=head;
        
        while(n>0){
           fast=fast->next;
           n--;
        }
        
        while(fast!=NULL){
            fast=fast->next;
            prevNode=slow;
            slow=slow->next;
        }
        
        if(prevNode==NULL){
            ListNode* copyNode=head;
            head=head->next;
            delete(copyNode);
        }
        else{
            ListNode* copyNode=slow;
            prevNode->next=slow->next;
            delete(copyNode);
        }
        
        return head;
        
        
        
    }
};