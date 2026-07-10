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
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;
        while (secondHalf != nullptr) {
            ListNode* cur = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = cur;
        }
        secondHalf = prev;

        ListNode* firstHalf = head;
        while (secondHalf != nullptr) {
            ListNode* firstNext = firstHalf->next;
            ListNode* secondNext = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = firstNext;

            firstHalf = firstNext;
            secondHalf = secondNext;
        }
    }
};
