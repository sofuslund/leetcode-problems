#include <iostream>
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
        ListNode* l = new ListNode(0);
        ListNode* c = l;
        ListNode* p = c;
        while (c != nullptr && !(l1 == nullptr && l2 == nullptr)) {
            int s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c->val;
            // Rightmost digit
            c->val = s - (s / 10 * 10);
            // Remainder
            c->next = new ListNode(s / 10);

            cout << "Nums: " << (l1 ? l1->val : 0) << ", " << (l2 ? l2->val : 0) << " Sum: " << c->val << " Sum(all): " << s << " Remainder: " << c->next->val << endl;
            // Next digits
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            p = c;
            c = c->next;
        }
        // If remainder is zero, delete zero padding
        if(c->val == 0) {
            delete c;
            p->next = nullptr;
        }
        return l;
    }
};
