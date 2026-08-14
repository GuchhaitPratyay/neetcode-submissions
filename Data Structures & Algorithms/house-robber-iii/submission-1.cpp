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
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0,0};
        }

        pair<int, int> leftPair = dfs(root->left);
        pair<int, int> rightPair = dfs(root->right);

        int withRoot = root->val + leftPair.second + rightPair.second;
        int withoutRoot = max(leftPair.first, leftPair.second) + max(rightPair.first, rightPair.second);

        return {withRoot, withoutRoot};
    }
public:
    int rob(TreeNode* root) {
        //Intution:
        //I can have two possiblities case 1: theif can robb the current and go the it's grandchild
        //case 2: Theif can skip robbing the current
        pair<int,int> result = dfs(root);

        return max(result.first, result.second);
    }
};