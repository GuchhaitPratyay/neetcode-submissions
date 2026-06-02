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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        queue<TreeNode*> myQueue;

        

        myQueue.push(root);
        while (!myQueue.empty()) {
            TreeNode* current = myQueue.front();
            myQueue.pop();
            swap(current->left, current->right);

            if (current->left != nullptr) myQueue.push(current->left);
            if (current->right != nullptr) myQueue.push(current->right);
        }

        return root;
    }
};
