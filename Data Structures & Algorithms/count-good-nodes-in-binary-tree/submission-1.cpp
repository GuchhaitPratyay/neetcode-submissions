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
    void dfs(TreeNode* root, int& goodNodes, int maxValue) {
        if (root == nullptr) return;

        if (root->val >= maxValue) goodNodes++;

        maxValue = max(maxValue, root->val);
        
        dfs(root->left, goodNodes, maxValue);
        
        dfs(root->right, goodNodes, maxValue);
    }
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int goodNodes = 0;
        int maxValue = INT32_MIN;
        dfs(root, goodNodes, maxValue);

        return goodNodes;        
    }
};
