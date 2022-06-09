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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode*headEvenNode=NULL,*headOddNode=NULL,*curNode=head,*prevOddNode=NULL,*prevEvenNode=NULL;
        int index=1;
        
        while(curNode!=NULL){
            if(index%2==1){
                if(headOddNode==NULL)
                    headOddNode=curNode;
                else
                    prevOddNode->next=curNode;
                prevOddNode=curNode;
            }
            else{
                if(headEvenNode==NULL)
                    headEvenNode=curNode;
                else
                    prevEvenNode->next=curNode;
                prevEvenNode=curNode;
            }
            index++;
            curNode=curNode->next;
        }
        
        prevOddNode->next=headEvenNode;
        prevEvenNode->next=NULL;
        return headOddNode;
        
        
    }
};