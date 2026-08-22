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
    int getMaxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftBest = getMaxPathSum(root->left);
        int rightBest = getMaxPathSum(root->right);

        int bestPath = root->val + max(leftBest, rightBest);
        
        return max(0, bestPath);
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        //self work
        int left = getMaxPathSum(root->left);
        int right = getMaxPathSum(root->right);

        //Now calculate the path including the current node;
        result = max(result, root->val + left + right);

        //recursive intuition
        dfs(root->left);
        dfs(root->right);
        //return max(0, pathSum);
    }
public:
    int result = INT32_MIN;
    int maxPathSum(TreeNode* root) {
        //Perform DFS traversal 
        dfs(root);
        return result;
    }
};
