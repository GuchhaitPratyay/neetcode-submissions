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

        ListNode* dummyNode = new ListNode(0);
        ListNode* current = dummyNode;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        ListNode* newHead = dummyNode->next;
        delete dummyNode;

        return newHead;
        //if (l1->val == 0 && l2->val == 0) return l1;
        //ListNode* temp_l1 = l1;
        //ListNode* temp_l2 = l2;
//
        //long number1 = 0L, number2 = 0L, number3 = 0L;
        //int length = 0;
        //while (temp_l1 != nullptr) {
        //    number1 += (temp_l1->val * pow(10, length++));
        //    temp_l1 = temp_l1->next;
        //}
        //length = 0;
        //while (temp_l2 != nullptr) {
        //    number2 += (temp_l2->val * pow(10, length++));
        //    temp_l2 = temp_l2->next;
        //}
        //number3 = number1 + number2;
        //
        //int val = (int)number3 % 10;
        //number3 = number3 / 10;
//
        //ListNode* newHead = new ListNode(val);
        //ListNode* tempNode = newHead;
        //while (number3) {            
        //    val = number3 % 10;
        //    number3 = number3 / 10;
        //    ListNode* temp = new ListNode(val);
        //    tempNode->next = temp;
        //    tempNode = tempNode->next;
        //}
//
        //return newHead;
    }
};
