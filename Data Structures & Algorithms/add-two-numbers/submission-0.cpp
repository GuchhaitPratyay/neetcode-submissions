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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp_l1 = l1;
        ListNode* temp_l2 = l2;

        int number1 = 0, number2 = 0, number3 = 0;
        int length = 0;
        while (temp_l1 != nullptr) {
            number1 += temp_l1->val * pow(10, length++);
            temp_l1 = temp_l1->next;
        }
        length = 0;
        while (temp_l2 != nullptr) {
            number2 += temp_l2->val * pow(10, length++);
            temp_l2 = temp_l2->next;
        }
        number3 = number1 + number2;
        
        int val = number3 % 10;
        number3 = number3 / 10;

        ListNode* newHead = new ListNode(val);
        ListNode* tempNode = newHead;
        while (number3) {            
            val = number3 % 10;
            number3 = number3 / 10;
            ListNode* temp = new ListNode(val);
            tempNode->next = temp;
            tempNode = tempNode->next;
        }

        return newHead;
    }
};
