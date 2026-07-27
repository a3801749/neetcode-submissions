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
        if (head == nullptr || head -> next == nullptr) { return; }
        ListNode* prev_slow = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }
        prev_slow->next = nullptr;
        ListNode* second = reverseList(slow);
        ListNode* after_head = head->next;
        ListNode* after_second = second->next;
        while (second != nullptr && head != nullptr) {
            after_head = head->next;
            after_second = second->next;

            head->next = second;
            second->next = after_head;

            if (after_head == nullptr && after_second != nullptr) {
                second->next = after_second;
            }

            head = after_head;
            second = after_second;
        }
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) { return head; }

        ListNode* current = head->next;
        head->next = nullptr;
        ListNode* after_current;

        while (current != nullptr) {
            after_current = current->next;
            current->next = head;
            head = current;
            current = after_current;
        }
        return head;
    }
};
