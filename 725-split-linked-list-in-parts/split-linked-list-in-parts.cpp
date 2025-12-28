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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> res(k);
        if(!head) return res;
        int n=0;
        ListNode* curr=head;
        while(curr) {
            curr=curr->next;
            n++;
        }
        int no_of_elem=n/k;
        int reminder=n%k;
        //vector<ListNode *> res(k);
        curr=head;
        for(int i=0;i<k;i++) {
            int count=no_of_elem;
            if(reminder) {
                count++;
                reminder--;
            }
            ListNode* prev;
            res[i]=curr;
            while(count) {
                prev=curr;
                curr=curr->next;
                count--;
            }
            prev->next=nullptr;

        }
        return res;
    }
};