/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";

        return to_string(root->val) + "," +
               serialize(root->left) + "," +
               serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }

private:
    TreeNode* build(stringstream& ss) {
        string value;
        getline(ss, value, ',');

        if (value == "#")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(value));
        node->left = build(ss);
        node->right = build(ss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));