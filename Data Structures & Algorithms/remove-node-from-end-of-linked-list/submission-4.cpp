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
        ListNode* removal_node = head;
        ListNode* temp_node = head;
        int listLength = 0;

        while (temp_node != nullptr) {
            temp_node = temp_node->next;
            ++listLength;
        }
        temp_node = nullptr;

        listLength -= n;

        for (int i = 0; i < listLength; ++i) {
            temp_node = removal_node;
            removal_node = removal_node->next;
        }

        if (listLength == 0) {
            head = removal_node->next;
            return head;
        } else {
            temp_node->next = removal_node->next;
        }
        removal_node = nullptr;
        free(removal_node);
        return head;

    }
};
