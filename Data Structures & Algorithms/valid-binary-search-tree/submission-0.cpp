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
    bool isValidBST(TreeNode* root) {
        

        queue<TreeNode*> qStore;
        qStore.push(root);

        while (!qStore.empty()) {
            TreeNode* temp = qStore.front();
            qStore.pop();

            if (temp->left != nullptr) {
                qStore.push(temp->left);
                if (temp->left->val > temp->val) return false;
            }
            if (temp->right != nullptr) {
                qStore.push(temp->right);
                if (temp->right->val < temp->val) return true;
            }
        }

        return true;
    }
};
