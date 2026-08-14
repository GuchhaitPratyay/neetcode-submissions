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
    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int includingRoot = root->val;

        if (root->left != nullptr) {
            includingRoot += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != nullptr) {
            includingRoot += rob(root->right->left) + rob(root->right->right);
        }

        int excludingRoot = rob(root->left) + rob(root->right);

        return max(includingRoot, excludingRoot);
    }
};