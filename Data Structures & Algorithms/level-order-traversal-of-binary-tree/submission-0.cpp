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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Intution
        //Perform BFS traversal level by level
        vector<vector<int>> result;

        if (root == nullptr) return result;

        queue<TreeNode*> q;
        int level = 0;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            result.push_back(vector<int>());
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                result[level].push_back(node->val);

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);

            }
            ++level;
        }

        return result;
    }
};
