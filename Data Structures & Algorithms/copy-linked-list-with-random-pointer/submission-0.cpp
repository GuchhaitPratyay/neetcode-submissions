/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //create a deepCopyHead
        if (head == nullptr) {
            return head;
        }

        Node* curr = head;
        unordered_map<Node*, Node*> oldToNewMap;

        while (curr != nullptr) {
            oldToNewMap.insert({curr, new Node(curr->val)});
            curr = curr->next;
        }

        curr = head;
//
        while (curr != nullptr) {
            oldToNewMap[curr]->next = oldToNewMap[curr->next];
            oldToNewMap[curr]->random = oldToNewMap[curr->random];
            curr = curr->next;
        }
        //Node* deepCopyNode = new Node(temp->val);
        //Node* temp_node = deepCopyNode;
        //temp = temp->next;
//
        //while (temp != nullptr) {
        //    Node* deepCopyTemp = new Node(temp->data);
        //    temp_node->next = deepCopyTemp;
        //    temp = temp->next;
        //}
//
        //temp = head;
        //temp_node = deepCopyNode;
//
        //while (temp != nullptr && temp_node != nullptr) {
//
        //}
//
        return oldToNewMap[head];
    }
};
