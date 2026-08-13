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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        //Check if the key value is less than root's value then delete from the left sub-tree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            //check if the target node has left child, if not present give the reference of right child 
            if (root->left == nullptr) {
                return root->right;
            }
            if (root->right == nullptr) {
                return root->left;
            } 
            //this the condition where the target node has both left and right child
            //find the in-order successor
            TreeNode* current = root->right;
            while (current->left != nullptr) {
                current = current->left;
            }
            //Give the root's left reference to current's left
            current->left = root->left;
            //Delete the target node, before that save it's right node
            TreeNode* rightNode = root->right;
            delete root;

            return rightNode;
        }

        return root;
    }
};