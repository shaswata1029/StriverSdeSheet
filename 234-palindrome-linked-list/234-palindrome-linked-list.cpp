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
    
    ListNode* reverseList(ListNode* head){
        ListNode *prevNode=NULL,*curNode=head,*nextNode=NULL;
        
        while(curNode!=NULL){
            nextNode=curNode->next;
            curNode->next=prevNode;
            prevNode=curNode;
            curNode=nextNode;
        }
        
        return prevNode;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return true;
        
        ListNode* slow=head,*fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reverseList(slow->next);
        
        slow=slow->next;
        ListNode* dummy=head;
        
        while(slow!=NULL){
            if(dummy->val!=slow->val)
                return false;
            dummy=dummy->next;
            slow=slow->next;
        }
        
        return true;
        
    }
};