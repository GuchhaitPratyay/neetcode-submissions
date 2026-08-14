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
private:
    int calculateHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        return (/*leftHeight == rightHeight ||*/ leftHeight == rightHeight-1 || leftHeight-1 == rightHeight) ? true : false;        
    }
};
