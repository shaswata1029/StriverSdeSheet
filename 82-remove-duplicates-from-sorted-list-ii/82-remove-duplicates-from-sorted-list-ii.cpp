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
        
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;
        
        ListNode* prevNode=dummyNode,*curNode=head;
        
        while(curNode!=NULL){
            int val=curNode->val;
            
            if(curNode->next!=NULL && curNode->next->val==val){
                while(curNode->next!=NULL && curNode->next->val==val)
                    curNode->next=curNode->next->next;
                prevNode->next=curNode->next;
                curNode=prevNode->next;
            }
            else{
                prevNode=curNode;
                curNode=curNode->next;
            }
        }
        
        return dummyNode->next;
        
    }
};