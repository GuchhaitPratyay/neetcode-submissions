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
    int dfs(TreeNode* root, int& result) {
        if (root == nullptr) {
            return 0;
        }

        //here we are calculating left and right maximum
        int leftBest = max(dfs(root->left, result), 0);
        int rightBest = max(dfs(root->right, result), 0);

        result = max(result, root->val + leftBest + rightBest);

        return root->val + max(leftBest, rightBest);
    }
    //int result = INT32_MIN;
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int result = root->val;
        //Perform DFS traversal 
        dfs(root, result);
        return result;
    }
};
