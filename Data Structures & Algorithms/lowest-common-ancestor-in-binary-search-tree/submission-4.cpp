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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Intuition is iteratively check is my both p and q are greater than or less than current
        //similar approach as recursive solution

        TreeNode* currentNode = root;

        while (currentNode != nullptr) {
            if (p->val < currentNode->val && q->val < currentNode->val) {
                currentNode = currentNode->left;
            } else if (p->val > currentNode->val && q->val > currentNode->val) {
                currentNode = currentNode->right;
            } else {
                return currentNode;
            }
        }

        return nullptr;
    }
};
