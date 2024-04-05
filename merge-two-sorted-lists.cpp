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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* node = nullptr;
        ListNode* head = nullptr;
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        while(l1 != nullptr || l2 != nullptr) {
            if(node == nullptr) {
                node = new ListNode();
                head = node;
            } else {
                node->next = new ListNode();
                node = node->next;
            }
            if(l1 == nullptr) {
                node->val = l2->val;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                node->val = l1->val;
                l1 = l1->next;
            } else if(l1->val<=l2->val) {
                node->val = l1->val;
                l1 = l1->next;
            } else {
                node->val = l2->val;
                l2 = l2->next;
            }
        }
        return head;
    }
};
