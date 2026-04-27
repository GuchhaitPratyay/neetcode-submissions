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
    void reorderList(ListNode* head) {
        ListNode* temp_ptr = head;
        //int listLength = 0;
        vector<int> tempVector;
        while (temp_ptr != nullptr) {
            tempVector.push_back(temp_ptr->val);
            temp_ptr = temp_ptr->next;
            //++list_length;
        }
        temp_ptr = head;

        auto startPtr = tempVector.begin();
        auto endPtr = tempVector.end();

        --endPtr;
        while (startPtr <= endPtr) {
            temp_ptr->val = *startPtr;
            temp_ptr = temp_ptr->next;
            if (temp_ptr == nullptr) break;
            temp_ptr->val = *endPtr;
            temp_ptr = temp_ptr->next;
            ++startPtr;
            --endPtr;
        }
        
    }
};
