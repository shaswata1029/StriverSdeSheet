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
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        
//         Iterative method
        
        ListNode *curNode=head;
        ListNode* prevNode=NULL;
        ListNode* nextNode=NULL;
        
        while(curNode!=NULL){
            nextNode=curNode->next;
            curNode->next=prevNode;
            prevNode=curNode;
            curNode=nextNode;
        }
        
        return prevNode;
        
        
    }
};