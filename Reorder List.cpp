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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list starting from slow->next
        ListNode* preMiddle = slow;
        ListNode* preCurrent = slow->next;
        while (preCurrent->next != NULL) {
            ListNode* current = preCurrent->next;
            preCurrent->next = current->next;
            current->next = preMiddle->next;
            preMiddle->next = current;
        }

        // Reordering the list
        ListNode* first = head;
        ListNode* second = preMiddle->next;
        while (first != preMiddle) {
            preMiddle->next = second->next;
            second->next = first->next;
            first->next = second;

            first = second->next;
            second = preMiddle->next;
        }
    }
};