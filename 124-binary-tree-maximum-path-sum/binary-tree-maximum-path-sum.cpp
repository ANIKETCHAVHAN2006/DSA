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
    int best;

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        int left = max(0, maxGain(node->left));
        int right = max(0, maxGain(node->right));

        best = max(best, node->val + left + right);

        return node->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        best = INT_MIN;
        maxGain(root);
        return best;
    }
};