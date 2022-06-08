/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
//         Approach-1
//         ListNode *curNode1=headA,*curNode2=headB;
//         int len1=0,len2=0;
        
//         while(curNode1!=NULL)
//         {
//             curNode1=curNode1->next;
//             len1++;
//         }
        
//         while(curNode2!=NULL){
//             curNode2=curNode2->next;
//             len2++;
//         }
        
//         curNode1=headA,curNode2=headB;
//         if(len1>len2){
//             swap(curNode1,curNode2);
//         }
        
//         int diff=abs(len1-len2);
//         while(diff>0){
//             curNode2=curNode2->next;
//             diff--;
//         }
        
//         while(curNode1!=NULL){
//             if(curNode1==curNode2)
//                 return curNode1;
//             curNode1=curNode1->next;
//             curNode2=curNode2->next;
//         }
        
        
//         return NULL;
        
        
//         Approach-2
        
        ListNode *curNode1=headA,*curNode2=headB;
        
        while(curNode1!=NULL or curNode2!=NULL){
            
            if(curNode1==NULL)
               curNode1=headB;
               
               if(curNode2==NULL)
               curNode2=headA;
            
            if(curNode1==curNode2)
                return curNode1;
            
            curNode1=curNode1->next;
            curNode2=curNode2->next;
        }
        
        return NULL;
        
        
        
    }
};