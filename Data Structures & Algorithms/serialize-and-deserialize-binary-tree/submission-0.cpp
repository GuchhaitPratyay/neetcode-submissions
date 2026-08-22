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

class Codec {
private:
    void dfsSerialize(TreeNode* root, vector<string>& result) {
        if (root == nullptr) {
            result.push_back("N");
            return;
        }

        result.push_back(to_string(root->val));

        dfsSerialize(root->left, result);
        dfsSerialize(root->right, result);
    }

    vector<string> split(string& data, char delimiter) {
        stringstream ss(data);
        vector<string> elements;
        string item;

        while (getline(ss, item, delimiter)) {
            elements.push_back(item);
        }

        return elements;
    }

    TreeNode* dfsDeserialize(vector<string>& values, int& index) {
        //base case
        if (values[index] == "N") {
            index++;
            return nullptr;
        }

        //self work
        TreeNode* root = new TreeNode(stoi(values[index++]));

        //recursively build left sub-tree and right sub-tree
        root->left = dfsDeserialize(values, index);
        root->right = dfsDeserialize(values, index);

        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //use a vector of string to the elements and N
        vector<string> result;
        dfsSerialize(root, result);
        string encode;

        for (string ch : result) {
            encode += ch;
            encode += ",";
        }
        return encode;       
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> elements = split(data, ',');

        int index = 0;

        return dfsDeserialize(elements, index);
    }
};
