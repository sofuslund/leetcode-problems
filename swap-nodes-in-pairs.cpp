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
    ListNode* swapPairs(ListNode* head) {
        // Length 0 or 1
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* curr = head;
        head = head->next; // When the first pair is swapped, then this is the head

        while(curr != nullptr && curr->next != nullptr) {
            ListNode* next = curr->next->next;
            // Pointer to fourth elm from current (or third if there is no fourth)
            ListNode* tmp = curr->next->next;
            if(tmp != nullptr && tmp->next != nullptr)
                tmp = tmp->next;
            
            curr->next->next = curr;
            curr->next = tmp;

            curr = next;
        }

        return head;
    }
};
