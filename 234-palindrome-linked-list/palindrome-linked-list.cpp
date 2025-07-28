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
    bool isPalindrome(ListNode* head) {
        vector<int>st;
        ListNode *slow=head, *fast=head;
        if(!head->next) return true;
        while(slow) {
            st.push_back(slow->val);
            slow=slow->next;
        }
        int l=0, r=st.size()-1;
        while(l<r) {
            if(st[l++]!=st[r--]) return false;
        }
        return true;
    }
};