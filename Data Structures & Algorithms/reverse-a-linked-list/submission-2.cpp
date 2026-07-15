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
    ListNode* reverseList(ListNode* head) {
        ListNode* next_ptr = nullptr;
        ListNode* prv_ptr = nullptr;

        while (head != nullptr) {
            next_ptr = head->next;
            head->next = prv_ptr;
            prv_ptr = head;
            head = next_ptr;
            
        }
        return prv_ptr;
    }
};
