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
    vector<int> result;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return result;
        stack<TreeNode*> myStack;
        vector<int> result;
        TreeNode* current = root;
        while (current != nullptr || !myStack.empty()) {
            if (current) {
                result.push_back(current->val);
                myStack.push(current);
                current = current->right;
            } else {
                current = myStack.top();
                myStack.pop();
                current = current->left;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};