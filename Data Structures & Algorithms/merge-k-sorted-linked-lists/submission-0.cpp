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
        //Intuition
        //we can use a data structure to collect all the elements and sort them in asending order

        if (lists.empty()) {
            return nullptr;
        }

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        //traverse each vector and push into the queue
        for (auto i : lists) {
            if (i != nullptr) {
                minHeap.push(i);
            }
            
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        //dummy->next = curr;
        //start traversal till the heap is empty
        while (!minHeap.empty()) {
            ListNode* temp = minHeap.top();
            minHeap.pop();
            curr->next = temp;            
            
            
            curr = curr->next;
            temp = temp->next;
            if (temp != nullptr) {
                minHeap.push(temp);
            }
        }

        return dummy->next;
    }
};
