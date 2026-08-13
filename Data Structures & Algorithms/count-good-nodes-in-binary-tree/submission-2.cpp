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
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<pair<TreeNode*, int>> qStore;
        qStore.push({root, INT32_MIN});

        int result = 0;

        while (!qStore.empty()) {
            pair<TreeNode*, int> temp = qStore.front();
            qStore.pop();

            if (temp.first->val >= temp.second) {
                ++result;
            }
            if (temp.first->left != nullptr) {
                qStore.push({temp.first->left, max(temp.second, temp.first->val)});
            }
            if (temp.first->right != nullptr) {
                qStore.push({temp.first->right, max(temp.second, temp.first->val)});
            }
        }

        return result;

    }
};
