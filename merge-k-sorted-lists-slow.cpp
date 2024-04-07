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
            if(n1 == nullptr) return false; // We do not want min_element to return nullptr each time
            if(n2 == nullptr) return true;
            return n1->val < n2->val;
        };
        while (lists.size() > 0) {
            ListNode* minElm = nullptr;
            int minElmIdx = 0;
            vector<ListNode*> newLists;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr) continue;
                newLists.push_back(lists[i]);

                if(minElm == nullptr || lists[i]->val < minElm->val) {
                    minElm = lists[i];
                    minElmIdx = newLists.size()-1;
                }
            }
            if(newLists.size() == 0)
                break;
            newLists[minElmIdx] = newLists[minElmIdx]->next;
            lists = newLists;

            node->next = minElm;
            node = node->next;

        }
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }
};
