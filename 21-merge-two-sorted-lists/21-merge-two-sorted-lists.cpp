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
    
    ListNode* merge(ListNode* head1,ListNode* head2 ){
        if(head1==NULL and head2==NULL)
            return NULL;
        
        if(head1==NULL){
            head2->next=merge(head1,head2->next);
            return head2;
        }
        
        if(head2==NULL){
            head1->next=merge(head1->next,head2);
            return head1;
        }
        
        if(head1->val>head2->val){
            head2->next=merge(head1,head2->next);
            return head2;
        }
        
        head1->next=merge(head1->next,head2);
        return head1;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        return merge(list1,list2);
    }
};