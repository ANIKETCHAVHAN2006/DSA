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
         ListNode dummy(0, head);

        int length = 0;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            ++length;
        }

        int index = length - n; // zero-based index of the node to remove
        ListNode* prev = &dummy;

        for (int i = 0; i < index; ++i) {
            prev = prev->next;
        }

        ListNode* nodeToDelete = prev->next;
        prev->next = nodeToDelete->next;
        delete nodeToDelete;

        return dummy.next;
    }
};