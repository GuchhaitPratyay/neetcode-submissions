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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       // if (!p && !q) return true;
        //perform a level order traversal 
        queue<TreeNode*> pStorage;
        queue<TreeNode*> qStorage;

        //push each root node to the queue
        pStorage.push(p);
        qStorage.push(q);
        
        while (!pStorage.empty() && !qStorage.empty()) {
            int pSize = pStorage.size(), qSize = qStorage.size();
            while (pSize-- && qSize--) {
                TreeNode* pNode = pStorage.front();
                TreeNode* qNode = qStorage.front();

                pStorage.pop();
                qStorage.pop();
                
                if (!pNode && !qNode) continue;
                if (!pNode || !qNode || pNode->val != qNode->val) {
                    return false;
                } 

                pStorage.push(pNode->left);
                pStorage.push(pNode->right);

                qStorage.push(qNode->left);
                qStorage.push(qNode->right);
            }
            
        } 
        return true;       
    }
};
