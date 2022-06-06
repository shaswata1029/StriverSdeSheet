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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        
        ListNode *curNode1=head1,*curNode2=head2;
        
        ListNode  *newHead=NULL,*curNode=NULL;
        int carry=0;
        
        while(curNode1!=NULL or curNode2!=NULL or carry>0){
            int sum=0;
            
            if(curNode1!=NULL)
                sum+=curNode1->val;
            
            if(curNode2!=NULL)
                sum+=curNode2->val;
            
            sum+=carry;
            
            ListNode* newNode=new ListNode(sum%10);
            if(newHead==NULL){
                newHead=newNode;
                curNode=newNode;
            }
            else{
                curNode->next=newNode;
                curNode=newNode;
            }
            
            carry=sum/10;
            
            if(curNode1!=NULL)
                curNode1=curNode1->next;
            
            if(curNode2!=NULL)
                curNode2=curNode2->next;
        } 
        
        
        return newHead;
        
    }
};