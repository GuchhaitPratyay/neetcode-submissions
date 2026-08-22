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
    TreeNode* dfs(vector<int>& preorder, int left, int right) {
        //base case
        //we need to stop once our left is greater than right
        if (left > right) {
            return nullptr;
        }

        //Create the root node and increament the counter
        TreeNode* root = new TreeNode(preorder[preorder_index++]);

        int mid = nodeMap[root->val];

        //recurive intuition
        root->left = dfs(preorder, left, mid - 1);

        root->right = dfs(preorder, mid + 1, right);

        return root;
    }


public:
    int preorder_index = 0;
    unordered_map<int, int> nodeMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        //use pre-order vector to put all the elements and it's index in the hash map
        for (int i = 0; i < inorder.size(); ++i) {
            nodeMap[inorder[i]] = i;
        }

        TreeNode* root = dfs(preorder, 0, preorder.size()-1);

        return root;
    }
};
