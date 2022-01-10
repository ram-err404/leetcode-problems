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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *curr = nullptr;
        int cf = 0;
        while(l1 || l2) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int v = v1 + v2 + cf;
            if(v >= 10) {
                cf = 1;
                v -= 10;
            } else {
                cf = 0;
            }
            ListNode *n = new ListNode(v);
            if(curr) {
                curr->next = n;
                curr = n;
            } else {
                head = curr = n;
            }
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(cf) {
            auto *n = new ListNode(1);
            curr->next = n;
            curr = n;
        }
        return head;
    }
};
