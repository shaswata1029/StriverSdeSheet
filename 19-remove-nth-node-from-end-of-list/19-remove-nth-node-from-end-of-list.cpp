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
        
        
        // Initially move the fast pointer by n steps so that the difference between slow            and fast pointers is n.
        // Then we move both slow and fast pointers by 1 step until fast reaches NULL.
        // The node which slow points at that moment is the required node to be deleted,so           we also keep a previous pointer to slow node to perform the delete operation.
        
        
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