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
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;

        if (root1 != nullptr && root2 != nullptr && root1->val == root2->val) {
            //Recuresively check if root-Left and root->right are similar
            bool leftSame = isSameTree(root1->left, root2->left);
            bool rightSame = isSameTree(root1->right, root2->right);
            return (leftSame && rightSame) ? true : false;
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;

        //Check if from the start the tree is same
        if (isSameTree(root, subRoot)) {
            return true;
        } 

        //if the the tree is not same then,
        //case 1: Left sub-tree might contain the subTree
        //        recursively call isSubtree function for left child
        bool presentInLeft = isSubtree(root->left, subRoot);
        //case 2: Right child might contain the similar sub-tree
        //        recursively call isSubtree function for right child
        bool presentInRight = isSubtree(root->right, subRoot);

        //If any one of the flag true then return true
        return (presentInLeft || presentInRight) ? true : false;
    }
};
