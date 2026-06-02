/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> myStack;

        TreeNode* current = root;
        while (current != nullptr || !myStack.empty()) {
            if (current != nullptr) {
                result.push_back(current->val);
                myStack.push(current->right);
                current = current->left;
            } else {
                current = myStack.top();
                myStack.pop();
            }
        } 

        return result;
    }
};