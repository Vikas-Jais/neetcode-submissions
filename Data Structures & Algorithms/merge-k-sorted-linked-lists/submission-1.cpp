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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> temp;

            for (int i = 0; i < lists.size(); i += 2) {
                if (i + 1 < lists.size()) {
                    temp.push_back(sort(lists[i], lists[i + 1]));
                } else {
                    temp.push_back(lists[i]);
                }
            }

            lists = temp;
        }

        return lists[0];
    }

    ListNode* sort(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        temp->next = (l1 != nullptr) ? l1 : l2;

        return dummy.next;
    }
};