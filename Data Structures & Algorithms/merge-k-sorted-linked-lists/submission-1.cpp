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
        ListNode res{};
        ListNode* tail = &res;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        } else if (list2 != nullptr) {
            tail->next = list2;
        }

        return res.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int n = lists.size();
        while (n > 1) {
            int j = 0;
            for (int i = 0; i + 1 < n; i += 2) {
                lists[j++] = mergeTwoLists(lists[i], lists[i + 1]);
            }
            if (n % 2 == 1) lists[j++] = lists[n - 1];
            n = j;
        }
        return lists[0];
    }
};
