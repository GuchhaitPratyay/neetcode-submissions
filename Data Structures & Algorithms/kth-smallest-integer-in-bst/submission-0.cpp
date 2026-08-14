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
    void inOrderTraversal(TreeNode* root, vector<int> &result) {
        if (root == nullptr) return;

        inOrderTraversal(root->left, result);
        result.push_back(root->val);
        inOrderTraversal(root->right, result);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;

        inOrderTraversal(root, result);

        int elementAt = result.size() - k;

        return result[result.size()-elementAt-1];
    }
};
