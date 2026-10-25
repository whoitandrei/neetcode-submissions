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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* before = &dummy;

        for (int i = 1; i < left; ++i) {
            before = before->next;
        }

        ListNode* curr = before->next;

        for (int i = 0; i < right - left; ++i) {
            ListNode* node = curr->next;

            curr->next = node->next;
            node->next = before->next;
            before->next = node;
        }

        return dummy.next;
    }
};