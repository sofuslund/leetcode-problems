#include <iostream>
#include <algorithm>
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
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* node = new ListNode();
        ListNode* head = node;

        auto nodeCompare = [](ListNode* n1, ListNode* n2) {
            if(n1 == nullptr) return true; // Nullptrs should be sorted lowest
            if(n2 == nullptr) return false;
            return n1->val < n2->val;
        };
        // First sort the heads in lists
        sort(lists.begin(), lists.end(), nodeCompare);
        while(lists.size()>0 && lists[0] == nullptr) { // Remove nullptrs
            lists.erase(lists.begin());
        }
        while (lists.size() > 0) {
            // Next node in merged list should be the smallest element
            node->next = lists[0];
            node = node->next;
            // First remove the list head so it can be inserted in the right place afterwards
            ListNode* newListHead = lists[0]->next;
            lists.erase(lists.begin());
            // Only reinsert if it is not a nullptr
            if(newListHead != nullptr) {
                // Insert the new list head in the right place so all list heads still are sorted
                lists.insert(lower_bound(lists.begin(), lists.end(), newListHead, nodeCompare), newListHead);
            }
        }
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }
};
