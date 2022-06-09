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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *curNode=head;
        
        while(curNode!=NULL){
            int val=curNode->val;
            
            while(curNode->next!=NULL and curNode->next->val==val)
                curNode->next=curNode->next->next;
            
            curNode=curNode->next;
        }
        
        return head;
        
    }
};