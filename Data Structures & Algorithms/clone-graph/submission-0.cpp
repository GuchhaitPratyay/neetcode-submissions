/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* dfsTraversal(Node* node, unordered_map<Node*, Node*>& oldToNew) {
        //base case
        if (node == nullptr) {
            return nullptr;
        }

        //check if the node is already present in the map,
        //if yes, that means we have already visited the node and created a copy of it.
        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        //self work
        //Create a copy of the node and store it in the map
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        //recursive intuition
        //Anyhow prepare the copy of the rest of the node
        for (Node* temp : node->neighbors) {
            Node* neighborCopy = dfsTraversal(temp, oldToNew);
            copy->neighbors.push_back(neighborCopy);
        }

        return copy;
    }

public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldToNew;
        Node* copyNode = dfsTraversal(node, oldToNew);

        return copyNode;
    }
};
