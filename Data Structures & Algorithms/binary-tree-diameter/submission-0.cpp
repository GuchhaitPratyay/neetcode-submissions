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
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        //diameter is nothing but left sub-tree height + right sub-tree height
        if (root == nullptr) return 0;

        // For each node get the heigt of the left and right sub-tree
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        //Add the left and right heights of the tree to get the diameter from one node
        int nodeDiameter = leftHeight + rightHeight;

        //recursively calculate the left diameter and right diameter
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        int treeDiameter = leftDiameter + rightDiameter;

        return max(treeDiameter, nodeDiameter);        
    }
};
