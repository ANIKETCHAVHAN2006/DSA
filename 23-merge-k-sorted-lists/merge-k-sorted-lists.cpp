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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }
        // CASE 1
        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else { // CASE 2
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }

    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if(start == end)
            return lists[start];
        
        if(start > end)
            return NULL;
        
        int mid = start + (end-start)/2;
        
        ListNode* l1 = partitionAndMerge(start, mid, lists);
        ListNode* l2 = partitionAndMerge(mid+1, end, lists);
        
        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        if(n == 0)
            return NULL;
        
        return partitionAndMerge(0, n-1, lists);
    }
};