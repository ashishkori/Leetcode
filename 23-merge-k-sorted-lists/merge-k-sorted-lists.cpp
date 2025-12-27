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
    ListNode * merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
  
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        queue<ListNode*> qu;
        for(auto x:lists) { 
            if(x) qu.push(x); 
        }

        while(qu.size()>1){
            ListNode* l1=qu.front();
             qu.pop();     
            ListNode* l2=qu.front();
             qu.pop(); 
            ListNode* newl=merge2Lists(l1,l2);
            qu.push(newl);
        }

        return   qu.empty() ? nullptr :qu.front();
    }
};