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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || k==1)
            return head;
        
        
//         Iterative approach
        ListNode *curNode=head;
        int len=0;
        
        while(curNode!=NULL){
            len++;
            curNode=curNode->next;
        }
        
        ListNode *dummyNode=new ListNode(-1);
        dummyNode->next=head;
        ListNode* prevHead=dummyNode;
        curNode=head;
        
        while(len>=k){
            
            int tempLen=k;
            ListNode* prevNode=NULL;
            ListNode *nextNode=NULL;
            ListNode *tempNode=curNode;
            
            while(tempLen>0){
                nextNode=curNode->next;
                curNode->next=prevNode;
                prevNode=curNode;
                curNode=nextNode;
                tempLen--;
            }
            
            prevHead->next=prevNode;
            prevHead=tempNode;
            
            len-=k;
        }
        
        prevHead->next=curNode;
        
        return dummyNode->next;
        
    }
};