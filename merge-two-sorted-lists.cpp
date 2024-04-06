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
        ListNode* node = new ListNode();
        ListNode* head = node;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1 != nullptr || l2 != nullptr) {
            if(l1 == nullptr) {
                node->next = l2;
                node = node->next;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                node->next = l1;
                node = node->next;
                l1 = l1->next;
            } else if(l1->val<=l2->val) {
                node->next = l1;
                node = node->next;
                l1 = l1->next;
            } else {
                node->next = l2;
                node = node->next;
                l2 = l2->next;
            }
        }
        ListNode* oldHead = head;
        head = head->next;
        delete oldHead;
        return head;
}
