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

        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        
//
        //ListNode* temp_list1 = nullptr;
        //ListNode* temp_list2 = nullptr;
        //ListNode* head_list1 = list1;
        //ListNode* head_list2 = list2;
//
//
        //while (head_list2 != nullptr && head_list1 != nullptr) {
        //    if (head_list2->val >= head_list1->data) {
        //        temp_list1 = head_list1;
        //        head_list1 = head_list1->next;
        //        
        //    }
        //}
//
        //return list2;
    }
};
