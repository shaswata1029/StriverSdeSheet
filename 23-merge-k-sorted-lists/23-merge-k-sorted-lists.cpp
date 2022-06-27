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

class Compare{
    public:
    bool operator()(const ListNode* node1,const ListNode* node2){
        return node1->val > node2->val;
    }
};

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *head=new ListNode(-1);
        ListNode *curNode=head;
        
        int n=lists.size();
        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;
        
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)
            pq.push(lists[i]);
        }
        
        while(!pq.empty()){
            ListNode* newNode=pq.top();
            pq.pop();
            
            
            
            curNode->next=new ListNode(newNode->val);
            curNode=curNode->next;
            
            if(newNode->next!=NULL)
            pq.push(newNode->next);
            
        }
        
        
        return head->next;
    }
};