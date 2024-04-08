#include <vector>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = head; // The first of the previous group (last after reversed)
        ListNode* curr = head; // The first of current group
        ListNode* last = head; // The last of current group
        ListNode* next = head; // The first of the next group

        while(next != nullptr) {
            // Create vector of all group nodes
            vector<ListNode*> group;
            group.push_back(last);
            int groupLen = 1;
            // Add nodes to current group
            for(; groupLen < k && last->next != nullptr; groupLen++) {
                last = last->next;
                cout << last->val << endl;
                group.push_back(last);
            }
            if(groupLen < k) { // Don't reverse the end group if it is not of length k
                last->next = nullptr;
                return head;
            }
            if(prev != curr) // If not first run
                prev->next = last; // Then set the last node of the previous group to the first node of this group (first after reversed)
            else // If first group
                head = last; // Set head to the last element / the first after reversed
            prev = curr;
            next = last->next;

            // Reorder node pointers to reverse current group
            for(int i = groupLen-1; i >= 1; i--) {
                cout << group[i]->val << endl;
                group[i]->next = group[i-1];
            }
            cout << curr->val << endl;
            curr->next = next;

            curr = next;
            last = next;
        }
        prev->next = nullptr;
        return head;
    }
};
