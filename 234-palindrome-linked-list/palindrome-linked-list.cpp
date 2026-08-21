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
    bool isPalindrome(ListNode* head) {
        vector<int>vec ;
        while(head != NULL){
            vec.push_back(head->val);
            head = head->next ;
        }
        int left = 0 , right = vec.size() - 1 ;
        while(left <= right){
            if(vec[left] != vec[right]){
                return false ;
            }
            left++ ; right-- ;
        }
        return true;
    }
};