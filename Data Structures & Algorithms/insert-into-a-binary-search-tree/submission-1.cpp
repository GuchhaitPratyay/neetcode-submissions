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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if (root == nullptr) return new TreeNode(val);
        //Initialize the current node to root
        TreeNode* current = root;

        //run an inifinite loop
        while (true) {
            //check if the value lesser than current then go left
            if (val < current->val) {
                if (current->left == nullptr) {
                    current->left = new TreeNode(val);
                    return root;
                }                
                current = current->left;
            } else if (val > current->val) {    //check if the value greater than current then go right
                if (current->right == nullptr) {
                    current->right = new TreeNode(val);
                    return root;
                }                
                current = current->right;
            }
        }

        return root;
    }
};