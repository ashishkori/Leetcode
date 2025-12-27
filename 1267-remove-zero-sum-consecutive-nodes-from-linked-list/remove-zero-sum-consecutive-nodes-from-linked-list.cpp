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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return nullptr;
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* curr=head;
        map<int, ListNode *> mp;
        mp[0]=dummy;
        int prefixSum=0;
        while(curr) {
            prefixSum+=curr->val;
            if(mp.find(prefixSum)!=mp.end()) {
               ListNode* start=mp[prefixSum];
               ListNode* tmp=start;
               int pSum=prefixSum;
               while(tmp!=curr) {
                  
                    tmp=tmp->next;
                    pSum+=tmp->val;
                    if(tmp!=curr) mp.erase(pSum);
                   
               }
               start->next = curr->next;

            } else {
                mp[prefixSum]=curr;
            }
            curr=curr->next;
        }
        return dummy->next;
        
    }
};