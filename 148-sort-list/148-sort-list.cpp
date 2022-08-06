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
    
    ListNode* findMid(ListNode*head,ListNode*tail){
        ListNode*fast=head,*slow=head;
        
        while(fast!=tail && fast->next!=tail){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode*head1,ListNode*head2){
        if(head1==NULL)
            return head2;
        
        if(head2==NULL)
            return head1;
        
        if(head1->val<=head2->val)
        {
            head1->next=merge(head1->next,head2);
            return head1;
        }
        
        head2->next=merge(head1,head2->next);
        return head2;
    }
    
    ListNode*mergeSort(ListNode *head, ListNode*tail){
        
        if(head==tail)
            return new ListNode(head->val);
        
       ListNode *mid=findMid(head,tail);
       ListNode *node1=mergeSort(head,mid);
       ListNode *node2=mergeSort(mid->next,tail);
       ListNode *newHead=merge(node1,node2); 
       return newHead; 
        
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode*tail=head;
        while(tail->next!=NULL)
            tail=tail->next;
        
        ListNode *newHead=mergeSort(head,tail);
        return newHead;
        
    }
};