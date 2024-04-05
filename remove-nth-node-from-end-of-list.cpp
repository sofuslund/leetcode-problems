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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nodes = 1;
        ListNode* node = head;
        ListNode* nodeBeforeN = head;
        while(node->next != nullptr) {
            node = node->next;
            nodes++;
            if(nodes>n+1) {
                nodeBeforeN = nodeBeforeN->next;
            }
        }

        if(nodes == n) {
            return head->next;
        }

        if(n==1) {
            nodeBeforeN->next = nullptr;
        } else {
            nodeBeforeN->next = nodeBeforeN->next->next;
        }

        return head;
    }
};
